#!/bin/bash
function pause(){
   read -p "$*"
}
mpic++ -fpermissive -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include" -I"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux" -v -c Lara.cpp -o Lara.o -Wfatal-errors
pause 'Press [Enter] key to continue...'
g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -v -time -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -ljvm -lmpi_cxx -lncurses
export LD_LIBRARY_PATH=/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server
