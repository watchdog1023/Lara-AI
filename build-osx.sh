#!/bin/sh
function pause() {
   read -p "$*"
}
function os_type
{
case `uname` in
   Darwin )
     DARWIN=1
	which brew && {	
	echo Brew found;
	brew update;
	brew install --verbose --debug boost opencv tesseract python wget mysql-connector-c++ zbar ncurses curlpp sfml mpich mysql@5.7;
	wget -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
	return;
	}
	which port && {
	port selfupdate;
	port install opencv boost ncurses python36 tesseract curl sfml sphinxbase mpich pocketsphinx wget gnutar cmake;
	wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.13-src.tar.gz;
	tar xfv mysql-connector-c++-8.0.13-src.tar.gz;
	cd mysql-connector-c++-8.0.13-src;	
	mkdir build;
	cd build;
	cmake ..;
	make;
	sudo make install;
	cd ..;
	cd ..;
	rm -vr mysql*;
	return;
	}     
;;
esac
}
sudo mkdir /usr/local/include/termcolor
cd /usr/local/include/termcolor/
wget -c https://raw.githubusercontent.com/ikalnytskyi/termcolor/master/include/termcolor/termcolor.hpp  
if [  -e /usr/bin/pip2 ]; then
   pip install --upgrade pip
   pip install pyscreenshot selenium datetime
fi
if [  -e /usr/bin/pip3 ]; then
   pip3 install --upgrade pip
   pip3 install pyscreenshot selenium datetime
fi
g++-8 -v -c Lara.cpp -o Lara.o -std=c++14 -I/Library/Frameworks/Python.framework/Versions/3.7/Headers -I/usr/local/include/sphinxbase -I/usr/local/include/pocketsphinx -Iinclude/ -Wall -Wextra -Wreturn-type -O3  -Wfatal-errors -fpermissive -Wc++-compat 2> LaraC.txt 
g++-8 -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++-8 -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++-8 -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++-8 -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++-8 -time -c include/qr_code/Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++-8 -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++-8 -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++-8 -time -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++-8 -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
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
    g++ -v -time -c include\qr_code\Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -c include\qr_code\QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -c include\qr_code\QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -fpermissive -c include\Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi 
