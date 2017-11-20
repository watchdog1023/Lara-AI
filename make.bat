@echo off
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
g++ -v -fpermissive -Iinclude/ -c Lara.cpp -o Lara.o -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors
g++ -v -c include\download.cpp -o download.o -Wwrite-strings -Wfatal-errors
g++ -v -c include\IRC\Thread.cpp -o Thread.o -Wfatal-errors
g++ -v -c include\IRC\IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -v -c include\IRC\IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -v -c include\IRC\IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -v -c include\qr_code\Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -v -c include\qr_code\QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -v -c include\qr_code\QrSegment.cpp -o QrSegment.o -Wfatal-errors
windres icon.rc icon.o
g++ -v -static -static-libgcc -static-libstdc++ -o Lara.exe Lara.o download.o Thread.o IRCHandler.o IRCSocket.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o icon.o -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core330.dll -lopencv_highgui330.dll -lopencv_imgproc330.dll -lopencv_imgcodecs330.dll -lopencv_videoio330.dll -lopencv_video330.dll -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36
PAUSE
rm -v *.o
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
