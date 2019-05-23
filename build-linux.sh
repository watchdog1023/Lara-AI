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
        sudo apt install libmpich-dev;
     fi;
     if [  -e /usr/bin/python3 ]; then
        sudo apt install python3;
     fi;
     if [  -e /usr/bin/pip3 ]; then
        sudo apt install python3-pip;
     fi;
     if [  -e /usr/bin/g++ ]; then
        sudo apt install build-essential make;
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
#if
wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-src.tar.gz
tar xfv mysql-connector-c++-8.0.16-src.tar.gz
cd mysql-connector-c++-8.0.16-src
mkdir build
cd build
cmake ..
make -j4
sudo make install
#else
#cd mysql-connector-c++-8.0.16-src
#mkdir build
#cd build
#sudo make install
#fi
if [  -e /usr/bin/pip2 ]; then
   pip install --upgrade pip
   pip install pyscreenshot selenium datetime
fi
if [  -e /usr/bin/pip3 ]; then
   pip3 install --upgrade pip
   pip3 install pyscreenshot selenium datetime
fi
mpic++ -fpermissive -std=c++14 -I"./chilkat-9.5.0-x86_64-linux-gcc/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++ -time -std=c++14  -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -L"./chilkat-9.5.0-x86_64-linux-gcc/lib" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
if [ ! -e ./lara ];then
    echo "Code Not Sane";
    cat LaraB.txt
    cat LaraC.txt
    return 1;
    if [ $TRAVIS_BRANCH != "master" ]; then
      pause 'Press [Enter] key to continue...'
    fi
else
    rm -vr lara *.o
    echo "Code is Sane";
    #pause 'Press [Enter] key to continue...'
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
