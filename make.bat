@echo off
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"
g++ -v -fpermissive -I HQGL_CLASS.h -c Lara.cpp -o Lara.o -Wwrite-strings
g++ -v -c download.cpp -o download.o -Wwrite-strings
windres icon.rc icon.o
g++ -v -static -static-libgcc -static-libstdc++ -I HQGL_CLASS.h -o Lara.exe Lara.o download.o icon.o -lwinmm C:\Mingw\lib\libws2_32.a  C:\Mingw\lib\libwininet.a
cd "C:\Users\Cameron\Desktop\code projects\C Programming\C++\WIP\AI(Home use)"