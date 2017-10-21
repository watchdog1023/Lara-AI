@echo off
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
g++ -v -fpermissive -Iinclude/ -c Lara.cpp -o Lara.o -Wwrite-strings -Wdeprecated-declarations
g++ -v -c include\download.cpp -o download.o -Wwrite-strings
g++ -v -c include\IRC\Thread.cpp -o Thread.o
g++ -v -c include\IRC\IRCClient.cpp -o IRCClient.o
g++ -v -c include\IRC\IRCSocket.cpp -o IRCSocket.o
g++ -v -c include\IRC\IRCHandler.cpp -o IRCHandler.o
g++ -v -c include\qr_code\Bitbuffer.cpp -o Bitbuffer.o
g++ -v -c include\qr_code\QrCode.cpp -o QrCode.o
g++ -v -c include\qr_code\QrSegment.cpp -o QrSegment.o
windres icon.rc icon.o
g++ -v -static -static-libgcc -static-libstdc++ -L"libs/" -o Lara.exe Lara.o download.o Thread.o IRCHandler.o IRCSocket.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o icon.o -L. -lchilkat-9.5.0 -lpthreadGCE2 -lpthreadGC2 -lpthread -lgdi32 -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core330.dll -lopencv_highgui330.dll -lopencv_imgproc330.dll -lopencv_imgcodecs330.dll -lopencv_videoio330.dll -lopencv_video330.dll
rm -v *.o
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
