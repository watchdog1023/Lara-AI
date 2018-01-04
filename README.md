# Lara-AI
compile with -fpermissive -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors flags 

Build with -static-libgcc -static-libstdc++ flags at start and -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core330.dll -lopencv_highgui330.dll -lopencv_imgproc330.dll -lopencv_imgcodecs330.dll -lopencv_videoio330.dll -lopencv_video330.dll -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36 -lzbar.dll flags at end(include all the .o files when building)

The Libaries used are termcolor,qrcodegen,OpenNN,tinyxml2,chilkat,zbar,boost and opencv3

Custom Compiler Toolchain at:


Pre-built(weekly builds,possibly unstable):
https://drive.google.com/open?id=0ByLm512z8MOiZURjcEJxazc3YWM

# Build Status
Windows:PASS
Linux:FAILED
