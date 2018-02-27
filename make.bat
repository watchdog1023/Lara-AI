@echo off
g++ -v -fpermissive -Iinclude/ -I"C:\Program Files (x86)\Java\jdk1.8.0_162\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_162\include\win32" -c Lara.cpp -o Lara.o -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors
g++ -v -c include\download.cpp -o download.o -Wwrite-strings -Wfatal-errors
g++ -v -c include\IRC\Thread.cpp -o Thread.o -Wfatal-errors
g++ -v -c include\IRC\IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -v -c include\IRC\IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -v -c include\IRC\IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -v -c include\qr_code\Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -v -c include\qr_code\QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -v -c include\qr_code\QrSegment.cpp -o QrSegment.o -Wfatal-errors
windres icon.rc icon.o
g++ -v -static -static-libgcc -static-libstdc++ -L"C:\Program Files (x86)\Java\jdk1.8.0_162\lib -o Lara.exe Lara.o download.o Thread.o IRCHandler.o IRCSocket.o IRCClient.o Bitbuffer.o QrCode.o QrSegment.o icon.o -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -lwsock32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core340.dll -lopencv_highgui340.dll -lopencv_imgproc340.dll -lopencv_imgcodecs340.dll -lopencv_videoio340.dll -lopencv_video340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36 -lpython27 -lzbar.dll -lsfml-audio -lsfml-network -lsfml-main -lsfml-system -lcurl -lbitcoinapi -lcryptopp -ljsoncpp -ljvm -ltesseract400.dll -lleptonica-1.75.0.dll
PAUSE
rm -v *.o
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
