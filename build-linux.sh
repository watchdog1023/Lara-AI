function pause () {
   read -p "$*"
}
function os_type
{
case $uname in
  Linux )
     LINUX=1
     
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
     if[ ! -e /usr/bin/mpic++ ]; 
     then apt install mpich; 
     fi; 
     if[ ! -e /usr/bin/python3 ]; 
     then apt install python3; 
     fi;
     if[ ! -e /usr/bin/pip3 ];
     then apt install python3-pip;
     fi;
     if[ ! -e /usr/bin/g++ ];
     then apt install build-essential make;
     fi
     return; 
     }
     which dnf && { 
     echo Fedora; 
     return; 
     }
     ;;
esac
}  
if [  -e /usr/bin/pip2 ]; then
   pip install --upgrade pip
   pip install pyscreenshot selenium datetime
fi
if [  -e /usr/bin/pip3 ]; then
   pip3 install --upgrade pip
   pip3 install pyscreenshot selenium datetime
fi
mpic++ -fpermissive -std=c++14 -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++ -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -time -c include/qr_code/Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -time -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++ -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
if [ ! -e ./lara ];then
    echo "Code Not Sane";
    pause 'Press [Enter] key to continue...'
else
    rm -vr lara *.o
    echo "Code is Sane";
    pause 'Press [Enter] key to continue...'
    mpic++ -v -fpermissive -std=c++14 -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors
    g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
    g++ -v -time -c include/qr_code/Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi 
