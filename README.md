# Lara-AI
compile with -fpermissive flag at start and -Wwrite-strings -Wdeprecated-declarations flag at end 

Build with -static -static-libgcc -static-libstdc++ -L"libs/"  flags at start and -lchilkat-9.5.0 -lpthreadGCE2 -lpthreadGC2 -lpthread -lgdi32 -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core330.dll -lopencv_highgui330.dll -lopencv_imgproc330.dll -lopencv_imgcodecs330.dll -lopencv_videoio330.dll -lopencv_video330.dll -lboost_atomic -lboost_chrono -lboost_thread flag at end(include all the .o files when building)

The Libaries used are termcolor,boost and opencv3

Custom Compiler Toolchain at:


Pre-built(weekly builds,possibly unstable):
https://drive.google.com/open?id=0ByLm512z8MOiZURjcEJxazc3YWM
