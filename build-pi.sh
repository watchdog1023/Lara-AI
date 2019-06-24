#!/bin/bash
function pause(){
   read -p "$*"
}
sudo -H pip install --upgrade pip
sudo -H pip3 install --upgrade pip
sudo -H pip install pyscreenshot selenium datetime
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
g++ -time -std=c++14  -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
if [ ! -e ./lara ];then
    echo "Code Not Sane";
    pause 'Press [Enter] key to continue...'
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
    g++ -v -time -std=c++14  -L"/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server" -o lara Lara.o Thread.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpicxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad

fi 
