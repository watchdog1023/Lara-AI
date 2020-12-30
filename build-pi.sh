#!/bin/bash
function pause(){
   read -p "$*"
}
mkdir -v assets/
mkdir -v assets/usr/
mkdir -v assets/usr/local/
sudo apt-get install libboost-all-dev libsfml-dev libtesseract-dev libmysql++-dev libmysqlclient-dev libcurl4-openssl-dev libpython3-dev libpython-dev libmysqlcppconn-dev;
if [ ! -e /usr/bin/pip3 ]; then
   sudo apt-get install python3-pip;
fi;
if [ ! -e /usr/bin/g++ ]; then
   sudo apt-get install build-essential make;
fi
if [ ! -e /usr/bin/swig ]; then
   sudo apt-get install swig;
fi
if [ ! -e /usr/bin/python3 ]; then
   sudo apt-get install python3;
fi;
#if [ ! -e sphinxbase-5prealpha/ ]; then
   wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
   tar xf sphinxbase-5prealpha.tar.gz
   cd sphinxbase-5prealpha
   ./configure --without-python
   make
   sudo make install
   cd ..
#else
#   cd sphinxbase-5prealpha
#   sudo make install
#   cd ..
#fi
#if [ ! -e pocketsphinx-5prealpha/ ]; then
   wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
   tar xf pocketsphinx-5prealpha.tar.gz
   cd pocketsphinx-5prealpha
   ./configure --without-python
   make
   sudo make install
   cd ..
#else
#   cd pocketsphinx-5prealpha
#   sudo make install
#   cd ..
#fi
if [ $TRAVIS_BRANCH == "master" ]; then
  #if [ ! -e mpich-3.3/ ]; then
   wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
   tar xf mpich-3.3.tar.gz;
   cd mpich-3.3/;
   ./configure --disable-fortran;
   make CXX="g++-8" CC="gcc-8" FC="gfortran-8";
   sudo make install;
   cd ../
 #else
 #  if [ "$(ls -A mpich-3.3/)" ]; then
 #     cd mpich-3.3/;
 #     sudo make install;
 #     cd ../
 #  else
 #     wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
 #     tar xf mpich-3.3.tar.gz;
 #     cd mpich-3.3/;
 #     ./configure --disable-fortran;
 #     make CXX="g++-8" CC="gcc-8" FC="gfortran-8";
 #     sudo make install;
 #     cd ../
 #  fi
 #fi
else
   sudo apt-get install libmpich-dev;
fi
if [ ! -e mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/ ]; then
    wget -c -q https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
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
    cp -vr libtitans.a assets/usr/local/lib
    cp -vr Titans.h assets/usr/local/include
    cd ../../
fi
sudo apt-get install libgstreamer-plugins-base1.0-dev build-essential cmake git libgtk2.0-dev pkg-config python-dev python-numpy libdc1394-22 libdc1394-22-dev libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev libtbb-dev libqt4-dev libmp3lame-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils unzip build-essential cmake cmake-curses-gui pkg-config libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libeigen3-dev libxvidcore-dev libx264-dev libgtk2.0-dev libv4l-dev v4l-utils libatlas-base-dev gfortran python2.7-dev python2-numpy python3-dev python3-numpy libavresample-dev libgphoto2-dev libopenexr-dev -y
wget -c https://github.com/opencv/opencv/archive/3.4.3.zip -O opencv_source.zip
wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O opencv_contrib.zip
unzip opencv_s*
unzip opencv_c*
cd opencv-*
mkdir build
cd build
cmake ..
make -j4
sudo make install
sudo ldconfig
cd ../..
sudo -H pip3 install --upgrade pip
sudo -H pip3 install pyscreenshot selenium datetime
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
sudo updatedb
sudo cp include/prim_type.h /usr/local/include/sphinxbase/prim_type.h
mpic++ -fpermissive -std=c++14 -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include" -I"/usr/include/python3.5m/" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux" -v -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -time -std=c++14 -fpermissive -I"./include"  -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++ -time -std=c++14  -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
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
    pause 'Press [Enter] key to continue...'
    mpic++ -v -fpermissive -I"assets/usr/local/include" -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include" -I"/usr/include/python3.5m/" -std=c++14 -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux" -v -c Lara.cpp -o Lara.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -std=c++14 -fpermissive -I"./include" -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -v -time -std=c++14  -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi
