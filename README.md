# Lara-AI
compile with -fpermissive -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors flags 

Build with -static-libgcc -static-libstdc++ flags at start and -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -lwsock32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core340.dll -lopencv_highgui340.dll -lopencv_imgproc340.dll -lopencv_imgcodecs340.dll -lopencv_videoio340.dll -lopencv_video340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36 -lpython27 -lzbar.dll -lsfml-audio -lsfml-network -lsfml-main -lsfml-system -lcurl -lbitcoinapi -lcryptopp -ljsoncpp -ljvm -ltesseract400.dll -lleptonica-1.75.0.dll flags at end(include all the .o files when building)

The Libaries used are termcolor,qrcodegen,OpenNN,tinyxml2,chilkat,zbar,MYSQL connector++,tesseract-ocr,leptonica,curl,opennn,websocketpp,voce,mpi,SFML,CUDA(Seperate build file),boost and opencv3

Custom Compiler Toolchain at:


Pre-built(weekly builds,possibly unstable):
https://drive.google.com/open?id=0ByLm512z8MOiZURjcEJxazc3YWM

# Build Status
Windows:PASS

Linux:FAILED
