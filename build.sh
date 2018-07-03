mpic++ -v -fpermissive -std=c++14 -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/ -c Lara.cpp -o Lara.o -Wfatal-errors
g++ -v -time -c include/download.cpp -o download.o -Wwrite-strings -Wfatal-errors
g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
#-ltinyxml2 -lbitcoinapi -lcryptopp -ljsoncpp -lfmpich2g -ltesseract -lleptonica
g++ -v -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -ljvm -lmpi_cxx -lncurses
export LD_LIBRARY_PATH=/usr/lib/jvm/java-9-openjdk-amd64/lib/server