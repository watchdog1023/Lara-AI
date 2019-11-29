@echo off
pip install --upgrade pip
pip3 install --upgrade pip
pip install pillow selenium datetime
pip3 install pillow selenium datetime
g++ -v -time -fpermissive -Iinclude/ -I"C:\Development_tools\Interpreters\Python35-32bit\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_162\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_162\include\win32" -c Lara.cpp -o Lara.o -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors
g++ -v -time -c include/download.cpp -o download.o -Wwrite-strings -Wfatal-errors
g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -v -time -c include/qr_code/Bitbuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -v -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -v -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -v -time -c include/SerialPort.cpp -o SerialPort.o -Wfatal-errors
windres icon.rc icon.o
g++ -v -time -static -static-libgcc -static-libstdc++ -L"C:\Development_tools\Interpreters\Python35-32bit\libs" -L"C:\Program Files (x86)\Java\jdk1.8.0_162\lib" -o Lara.exe  icon.o IRCClient.o SerialPort.o IRCSocket.o IRCHandler.o Bitbuffer.o QrCode.o QrSegment.o Thread.o Lara.o download.o -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -lwsock32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core340.dll -lopencv_highgui340.dll -lopencv_imgproc340.dll -lopencv_imgcodecs340.dll -lopencv_videoio340.dll -lopencv_video340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36 -lpython27 -lzbar.dll -lsfml-audio -lsfml-network -lsfml-main -lsfml-system -lcurl -lbitcoinapi -lcryptopp -ljsoncpp -ltesseract400.dll -lmpi -lmpicxx -lfmpich2g -lpocketsphinx -lsphinxbase
PAUSE

:UnZipFile <ExtractTo> <newzipfile>
set vbs="%temp%\_.vbs"
if exist %vbs% del /f /q %vbs%
>%vbs%  echo Set fso = CreateObject("Scripting.FileSystemObject")
>>%vbs% echo If NOT fso.FolderExists(%1) Then
>>%vbs% echo fso.CreateFolder(%1)
>>%vbs% echo End If
>>%vbs% echo set objShell = CreateObject("Shell.Application")
>>%vbs% echo set FilesInZip=objShell.NameSpace(%2).items
>>%vbs% echo objShell.NameSpace(%1).CopyHere(FilesInZip)
>>%vbs% echo Set fso = Nothing
>>%vbs% echo Set objShell = Nothing
cscript //nologo %vbs%
if exist %vbs% del /f /q %vbs%
