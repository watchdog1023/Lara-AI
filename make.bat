@echo off
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
g++ -v -fpermissive -c Lara.cpp -o Lara.o -Wwrite-strings
g++ -v -c include\download.cpp -o download.o -Wwrite-strings
windres icon.rc icon.o
g++ -v -static -static-libgcc -static-libstdc++ -L"libs/" -o Lara.exe Lara.o download.o icon.o -L. -lchilkat-9.5.0 -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lpthread -lopencv_core249 -lopencv_highgui249  
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"