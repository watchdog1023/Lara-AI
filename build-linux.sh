#!/bin/bash
function pause () {
   read -p "$*"
}
if [ $GITPOD == "YES" ]; then
    mkdir assets/
fi
if [ $ENV_TYPE != "Docker"]; then
   which yum && {
        echo centos;
        yum group install "Development Tools";
        yum install kernel-devel;
        if [ ! -e /usr/bin/g++ ];
        then yum install gcc-c++;
        fi;
        if [ ! -e /usr/bin/wget ];
        then yum install wget;
        fi;
        if [ ! -e /usr/bin/mpic++ ];
        then wget -c http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.xz;
        tar xfv autoconf-2.69.tar.xz;
        cd autoconf-2.69/;
        ./configure;
        make;
        sudo make install;
        cd ..;
        wget -c http://ftp.gnu.org/gnu/automake/automake-1.16.1.tar.gz;
        tar xfv automake-1.16.1.tar.gz;
        cd autmake-1.16.1;
        ./configure;
        make;
        sudo make install;
        cd ..;
        wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
        tar xfv mpich-3.3.tar.gz;
        cd mpich-3.3/;
        ./autogen.sh;
        ./configure;
        make;
        sudo make install;
        cd ..;
        fi;
        #if[ ! -e /usr/bin/python3 ];
        #then #yum install https://centos7.iuscommunity.org/ius-release.rpm;
        #yum install python36u;
        #fi;
        #if[ ! -e /usr/bin/pip3];
        #then yum -y install python36u-pip;
        #ln -sf /usr/bin/pip3.6 /usr/bin/pip3;
        #fi;
        return;
        }
   
        which zypper && {
        echo opensuse;
        zypper update;
        zypper install gcc-c++
        return;
        }
        which apt-get && {
        echo debian;
        if [ ! -e /usr/bin/mpic++ ]; then
         if [ $TRAVIS_BRANCH == "master" ]; then
            if [ ! -e mpich-3.3/ ]; then
               wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
               tar xf mpich-3.3.tar.gz;
               cd mpich-3.3/;
               ./configure --disable-fortran;
               make CXX="g++" CC="gcc-8" FC="gfortran-8";
               sudo make install;
               cd ../
             else
               if [ "$(ls -A mpich-3.3/)" ]; then
                  cd mpich-3.3/;
                  sudo make install;
                  cd ../
               else
                  wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
                  tar xf mpich-3.3.tar.gz;
                  cd mpich-3.3/;
                  ./configure --disable-fortran;
                  make CXX="g++" CC="gcc-8" FC="gfortran-8";
                  sudo make install;
                  cd ../
               fi
             fi
        else
           sudo apt-get install libmpich-dev;
        fi
        fi;
        if [ ! -e /usr/bin/python3 ]; then
           sudo apt-get install python3;
        fi;
        if [ ! -e /usr/bin/pip3 ]; then
           sudo apt-get install python3-pip;
        fi;
        if [ ! -e /usr/bin/g++ ]; then
           sudo apt-get install build-essential make;
        fi
        if [ ! -e /usr/bin/swig ]; then
           sudo apt-get install swig;
        fi
        sudo apt-get install libboost-all-dev libsfml-dev libtesseract-dev;
        }
        which dnf && {
        echo Fedora;
        return;
        }
   if [ ! -e opencv-3.4.3/ ]; then 
      wget -c https://github.com/opencv/opencv/archive/3.4.3.zip
      wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O contrib-343.zip
      unzip -qq 3.4.3.zip
      unzip -qq contrib-343.zip
      cd opencv-3.4.3/
      mv -vf ../opencv_contrib-3.4.3/* .
      mkdir build
      cd build
      cmake -quiet ..
      make -j4
      if [ $GITPOD == "YES" ]; then
       make install DESTDIR="/workspace/Lara-AI/assets/"
      else
       sudo make install
      fi
      cd ../..
   else
      if [ "$(ls -A opencv-3.4.3/)" ]; then
         cd opencv-3.4.3/
         cd build
         if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Lara-AI/assets/"
         else
           sudo make install
         fi
         cd ../..
      else
         wget -c https://github.com/opencv/opencv/archive/3.4.3.zip
         wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O contrib-343.zip
         unzip -qq 3.4.3.zip
         unzip -qq contrib-343.zip
         cd opencv-3.4.3/
         mv -v ../opencv_contrib-3.4.3/* .
         mkdir build
         cd build
         cmake -quiet ..
         make -j4
         if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Lara-AI/assets/"
         else
           sudo make install
         fi
         cd ../..
      fi
   fi
   if [ ! -e  assets/ ]; then
       mkdir -v assets/
       mkdir -v assets/usr/
       mkdir -v assets/usr/local/
   fi
   if [ ! -e jsoncpp ]; then
       git clone https://github.com/open-source-parsers/jsoncpp.git
       cd jsoncpp
       mkdir build
       cd build
       cmake -DBUILD_SHARED_LIBS=OFF ..
       make -j4
       if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Lara-AI/assets/"
           cd "/workspace/Lara-AI/assets/usr/local/include"
           mkdir jsoncpp
           mv json jsoncpp/
           cd "/workspace/Lara-AI/assets/usr"
       else
           sudo make install
       fi
       cd ../..
   else
       cd jsoncpp
       rm -vr build
       git pull
       mkdir build
       cd build
       cmake -DBUILD_SHARED_LIBS=OFF ..
       make -j4
       if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Lara-AI/assets/"
           cd "/workspace/Lara-AI/assets/usr/local/include"
           mkdir jsoncpp
           mv json jsoncpp/
           cd "/workspace/Lara-AI/assets/usr"
       else
           sudo make install
       fi
       cd ../..
   fi
   if [ ! -e mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/ ]; then
      wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
      tar xf mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
      cp -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/jdbc/* mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/
      cp -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib64/ mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib/
      if [ $GITPOD == "YES" ]; then
         cp -vr mysql-*/* /workspace/Lara-AI/assets/usr/local/
      else
         cp -vr mysql-*/* assets/usr/local/
      fi
   else
      cp -vr mysql-*/* assets/usr/local/
   fi
   if [ ! -e libtensorflow-cpu-linux-x86_64-1.13.1/ ]; then
      wget -c https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz
      mkdir libtensorflow-cpu-linux-x86_64-1.13.1
      tar xf libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz -C libtensorflow-cpu-linux-x86_64-1.13.1
      cp -vr libtensorflow-*/* assets/usr/local/
   else
      cp -vr libtensorflow-*/* assets/usr/local/
   fi
   if [ ! -e sphinxbase-5prealpha/ ]; then
      wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
      tar xf sphinxbase-5prealpha.tar.gz
      cd sphinxbase-5prealpha
      ./configure
      make
      if [ $GITPOD == "YES" ]; then
       make install DESTDIR="/workspace/Lara-AI/assets/"
      else
       sudo make install
      fi
      cd ..
   else
     if [ "$(ls -A sphinxbase-5prealpha/)" ]; then
        cd sphinxbase-5prealpha
        if [ $GITPOD == "YES" ]; then
         make install DESTDIR="/workspace/Lara-AI/assets/"
        else
         sudo make install
        fi
        cd ..
   else
         wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
         tar xf sphinxbase-5prealpha.tar.gz
         cd sphinxbase-5prealpha
         ./configure
         make
         if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Lara-AI/assets/"
         else
           sudo make install
         fi
         cd ..
     fi
   fi
   if [ ! -e pocketsphinx-5prealpha/ ]; then
      wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
      tar xf pocketsphinx-5prealpha.tar.gz
      cd pocketsphinx-5prealpha
      ./configure
      make
      if [ $GITPOD == "YES" ]; then
       make install DESTDIR="/workspace/Lara-AI/assets/"
      else
       sudo make install
      fi
      cd ..
   else
     if [ "$(ls -A pocketsphinx-5prealpha/)" ]; then
        cd pocketsphinx-5prealpha
        if [ $GITPOD == "YES" ]; then
          make install DESTDIR="/workspace/Lara-AI/assets/"
        else
          sudo make install
        fi
        cd ..
     else
        wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
        tar xf pocketsphinx-5prealpha.tar.gz
        cd pocketsphinx-5prealpha
        ./configure
        make
        if [ $GITPOD == "YES" ]; then
          make install DESTDIR="/workspace/Lara-AI/assets/"
        else
          sudo make install
        fi
        cd ..
     fi
   fi
   if [ ! -e libtitan ]; then
       git clone https://github.com/Titan-Technology/libtitan.git
       cd libtitan
       git pull
       cd C++/
       chmod -v 777 make.sh
       ./make.sh
       if [ $GITPOD == "YES" ]; then
         cp -vr libtitans.a /workspace/Lara-AI/assets/usr/local/lib
         cp -vr Titans.h /workspace/Lara-AI/assets/usr/local/include/
       fi
       cd ../../
   fi
fi
if [  -e /usr/bin/pip2 ]; then
   sudo -H pip install --upgrade pip
   sudo -H pip install --upgrade setuptools
   sudo -H pip install --upgrade pyscreenshot selenium datetime requests
fi
if [  -e /usr/bin/pip3 ]; then
   sudo -H pip3 install --upgrade pip
   sudo -H pip3 install --upgrade setuptools
   sudo -H pip3 install --upgrade pyscreenshot selenium datetime requests
fi
if [ ! -e data/obj_detect/ ]; then
   mkdir data/obj_detect/
fi
if [ ! -e data/obj_detect/yolov3.weights ]; then
   wget https://pjreddie.com/media/files/yolov3.weights -O ./data/obj_detect/yolov3.weights
fi
if [ ! -e data/obj_detect/yolov3.cfg ]; then
   wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg?raw=true -O ./data/obj_detect/yolov3.cfg
fi
if [ ! -e data/obj_detect/coco.names ]; then
   wget https://github.com/pjreddie/darknet/blob/master/data/coco.names?raw=true -O ./data/obj_detect/coco.names
fi
if [ $GITPOD == "YES" ]; then 
    cp include/prim_type.h assets/usr/local/include/sphinxbase/prim_type.h 
else 
    sudo cp include/prim_type.h /usr/local/include/sphinxbase/prim_type.h
fi
sudo ldconfig
sudo updatedb
if [ $1 == "alive" ]; then
    if [ $TRAVIS_BRANCH == "master" ]; then
        mpic++ -DALIVE -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"/usr/include/python3.6m/" -c Lara.cpp -o Lara.o -Wfatal-errors -Wdeprecated 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"../libtian/C++" -L"assests/usr/lib/" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.6m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp 2> LaraB.txt
    elif [ $GITPOD == "YES" ]; then
        mpic++ -DALIVE -fpermissive -std=c++14 -I"../libtitan/C++/" -I"assets/usr/local/include" -I"assets/usr/local/include/pocketsphinx" -I"assets/usr/local/include/sphinxbase" -I"include/" -I"/usr/include/python3.7" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -I"assets/usr/local/include" -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"../libtian/C++/" -L"assets/usr/local/lib" -L"/usr/lib/python3.7/config-3.7m-x86_64-linux-gnu/" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp 2> LaraB.txt
    else
        mpic++ -DALIVE -fpermissive -std=c++14 -I"/usr/include/python3.7m/" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"assets/usr/local/include" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"assets/usr/local/lib" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp 2> LaraB.txt
    fi
    if [ ! -e ./lara-alive ]; then
        echo "Code Not Sane";
        echo "========================Build Stage Output========================================"
        cat LaraB.txt
        echo "========================Compile Stage Output======================================"
        cat LaraC.txt
        echo "=================================================================================="
        if [ $TRAVIS_BRANCH != "master" ]; then
            pause 'Press [Enter] key to continue...'
        else
            exit 1;
        fi
    else
        rm -vr lara-alive *.o
        echo "Code is Sane";
        if [ $TRAVIS_BRANCH != "master" ]; then
            pause 'Press [Enter] key to continue...'
        fi
        if [ $TRAVIS_BRANCH == "master" ]; then
            mpic++ -DALIVE -v -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"/usr/include/python3.6m/" -c Lara.cpp -o Lara.o -Wfatal-errors -Wdeprecated
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"assests/usr/lib/" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.6m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp
        elif [ $GITPOD == "YES" ]; then
            mpic++ -DALIVE -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"assets/usr/local/include/pocketsphinx" -I"assets/usr/local/include/sphinxbase" -I"include/" -I"/usr/include/python3.7" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -I"assets/usr/local/include" -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"assets/usr/local/lib" -L"/usr/lib/python3.7/config-3.7m-x86_64-linux-gnu/" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp
        else
            mpic++ -DALIVE -v -fpermissive -std=c++14 -I"/usr/include/python3.7m/" -I"libtitan/C++/" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"assets/usr/local/include" -c Lara.cpp -o Lara.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors 
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"assets/usr/local/lib" -o lara-alive Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp
        fi
        if [ -e ./lara-alive ]; then
            clear
            echo "Alive Build Successful"
            exit 0
        fi
    fi
else
    if [ $TRAVIS_BRANCH == "master" ]; then
        mpic++ -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include"-I"/usr/local/include/sphinxbase/" -I"./include/" -I"/usr/include/python3.6m/" -c Lara.cpp -o Lara.o -Wfatal-errors -Wdeprecated 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"assests/usr/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.6m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp 2> LaraB.txt
    elif [ $GITPOD == "YES" ]; then
        mpic++ -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"assets/usr/local/include/pocketsphinx" -I"assets/usr/local/include/sphinxbase" -I"include/" -I"/usr/include/python3.7" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -I"assets/usr/local/include" -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"assets/usr/local/lib" -L"/usr/lib/python3.7/config-3.7m-x86_64-linux-gnu/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp 2> LaraB.txt
    else
        mpic++ -fpermissive -std=c++14 -I"libtitan/C++/" -I"/usr/include/python3.7m/" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"assets/usr/local/include" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
        g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
        g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
        g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
        g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
        g++ -time -std=c++14 -L"libtitan/C++/" -L"assets/usr/local/lib" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp -ljsoncpp 2> LaraB.txt
    fi
    if [ ! -e ./lara ]; then
        echo "Code Not Sane";
        echo "========================Build Stage Output========================================"
        cat LaraB.txt
        echo "========================Compile Stage Output======================================"
        cat LaraC.txt
        echo "=================================================================================="
        if [ $TRAVIS_BRANCH != "master" ]; then
            pause 'Press [Enter] key to continue...'
        else
            exit 1;
        fi
    else
        rm -vr lara *.o
        echo "Code is Sane";
        if [ $TRAVIS_BRANCH != "master" ]; then
            pause 'Press [Enter] key to continue...'
        fi
        if [ $TRAVIS_BRANCH == "master" ]; then
            mpic++ -v -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"/usr/include/python3.6m/" -c Lara.cpp -o Lara.o -Wfatal-errors -Wdeprecated
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"assests/usr/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.6m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp
        elif [ $GITPOD == "YES" ]; then
            mpic++ -fpermissive -std=c++14 -I"libtitan/C++/" -I"assets/usr/local/include" -I"assets/usr/local/include/pocketsphinx" -I"assets/usr/local/include/sphinxbase" -I"include/" -I"/usr/include/python3.7" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -I"assets/usr/local/include" -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"assets/usr/local/lib" -L"/usr/lib/python3.7/config-3.7m-x86_64-linux-gnu/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp_static -ljsoncpp
        else
            mpic++ -fpermissive -std=c++14 -I"/usr/include/python3.7m/" -I"libtitan/C++/" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"assets/usr/local/include" -c Lara.cpp -o Lara.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
            g++ -v -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors 
            g++ -v -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
            g++ -v -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
            g++ -v -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
            g++ -v -std=c++14 -L"libtitan/C++/" -L"assets/usr/local/lib" -L"libtitan/C++/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.7m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad -ltitans -ljsoncpp
        fi
        if [ -e ./lara ]; then
            clear
            echo "Build Successful"
            exit 0
        fi
    fi
fi

