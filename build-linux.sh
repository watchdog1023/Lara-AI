#!/bin/bash
function pause () {
   read -p "$*"
}
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
            make CXX="g++-8" CC="gcc-8" FC="gfortran-8";
            sudo make install;
            cd ../
          else
            cd mpich-3.3/;
            sudo make install;
            cd ../
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
     sudo apt-get install libboost-dev libsfml-dev libtesseract-dev;
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
   mv -v ../opencv_contrib-3.4.3/* .
   mkdir build
   cd build
   cmake -quiet ..
   make -j4
   sudo make install
   cd ../..
else
   cd opencv-3.4.3/
   cd build
   sudo make install
   cd ../..
fi
if [ ! -e chilkat-9.5.0-x86_64-linux-gcc/ ]; then
   wget -c https://chilkatdownload.com/9.5.0.78/chilkat-9.5.0-x86_64-linux-gcc.tar.gz
   tar xf chilkat-9.5.0-x86_64-linux-gcc.tar.gz
   sudo mv -v chilkat-9.5.0-x86_64-linux-gcc/include chilkat-9.5.0-x86_64-linux-gcc/chilkat
fi
if [ ! -e mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/ ]; then
   wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
   tar xf mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
fi
if [ ! -e libtensorflow-cpu-linux-x86_64-1.13.1/ ]; then
   wget -c https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz
   mkdir libtensorflow-cpu-linux-x86_64-1.13.1
   tar xf libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz -C libtensorflow-cpu-linux-x86_64-1.13.1
fi
if [ ! -e sphinxbase-5prealpha/ ]; then
   wget -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
   tar xf sphinxbase-5prealpha.tar.gz
   cd sphinxbase-5prealpha
   ./configure
   make
   sudo make install
   cd ..
else
   cd sphinxbase-5prealpha
   sudo make install
   cd ..
fi
if [ ! -e pocketsphinx-5prealpha/ ]; then
   wget -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
   tar xf pocketsphinx-5prealpha.tar.gz
   cd pocketsphinx-5prealpha
   ./configure
   make
   sudo make install
   cd ..
else
   cd pocketsphinx-5prealpha
   sudo make install
   cd ..
fi
if [  -e /usr/bin/pip2 ]; then
   sudo -H pip install --upgrade pip
   sudo -H pip install setuptools
   sudo -H pip install pyscreenshot selenium datetime 
fi
if [  -e /usr/bin/pip3 ]; then
   sudo -H pip3 install --upgrade pip
   sudo -H pip3 install setuptools
   sudo -H pip3 install pyscreenshot selenium datetime
fi
sudo cp include/prim_type.h /usr/local/include/sphinxbase/prim_type.h
sudo ldconfig
mpic++ -fpermissive -std=c++14 -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"libtensorflow-cpu-linux-x86_64-1.13.1/include" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/jdbc" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/mysql" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/mysqlx" -I"./chilkat-9.5.0-x86_64-linux-gcc/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++-8 -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++-8 -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++-8 -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++-8 -time -std=c++14 -L"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib64" -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -L"./chilkat-9.5.0-x86_64-linux-gcc/lib" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
if [ ! -e ./lara ];then
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
    mpic++ -v -fpermissive -std=c++14 -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors
    g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
    g++ -v -time -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi
