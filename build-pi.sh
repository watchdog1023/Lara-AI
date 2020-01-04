#!/bin/bash
function pause(){
   read -p "$*"
}
sudo apt-get install libboost-all-dev libsfml-dev libtesseract-dev libcurl4-openssl-dev install libpython3-dev libpython-dev;
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
if [ ! -e mysql-connector-c++-8.0.18-src/ ]; then
   wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.18-src.tar.gz
   tar xf mysql-connector-c++-8.0.18-src.tar.gz
   cd mysql-connector-c++-8.0.18-src/
   mkdir build
   cd build
   cmake ..
   make
   sudo make install
   cd ../..
else
   cd mysql-connector-c++-8.0.18-src/
   cd build
   sudo make install
   cd ../..
fi
if [ ! -e sphinxbase-5prealpha/ ]; then
   wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
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
   wget --no-check-certificate -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
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
   if [ "$(ls -A mpich-3.3/)" ]; then
      cd mpich-3.3/;
      sudo make install;
      cd ../
   else
      wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
      tar xf mpich-3.3.tar.gz;
      cd mpich-3.3/;
      ./configure --disable-fortran;
      make CXX="g++-8" CC="gcc-8" FC="gfortran-8";
      sudo make install;
      cd ../
   fi
 fi
else
   sudo apt-get install libmpich-dev;
fi
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
mpic++ -fpermissive -std=c++14 -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux" -v -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
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
    mpic++ -v -fpermissive -std=c++14 -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux" -v -c Lara.cpp -o Lara.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -v -time -std=c++14  -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi 
