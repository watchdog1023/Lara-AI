# Lara-AI
[![Build Status](https://travis-ci.org/watchdog1023/Lara-AI.svg?branch=master)](https://travis-ci.org/watchdog1023/Lara-AI)
[![CodeFactor](https://www.codefactor.io/repository/github/watchdog1023/lara-ai/badge/master)](https://www.codefactor.io/repository/github/watchdog1023/lara-ai/overview/master)

compile with -fpermissive -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors flags 

NB:Linux users should use mpic++ to compile 

# Windows Specify 
Build with -static-libgcc -static-libstdc++ flags at start and -lchilkat-9.5.0 -lgdi32 -lcrypt32 -lws2_32 -lwsock32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core340.dll -lopencv_highgui340.dll -lopencv_imgproc340.dll -lopencv_imgcodecs340.dll -lopencv_videoio340.dll -lopencv_video340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread -lopennn -ltinyxml2 -lpython36 -lzbar.dll -lsfml-audio -lsfml-network -lsfml-main -lsfml-system -lcurl -lbitcoinapi -lcryptopp -ljsoncpp -ltesseract400.dll -lleptonica-1.75.0.dll -lpocketsphinx -lsphinxbase flags at end(include all the .o files when building)

# Linux Specify
Build with -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase flags at end(include all the .o files when building)

# Libs
The Libaries used are termcolor,qrcodegen,chilkat,zbar,MYSQL connector++,tesseract-ocr,leptonica,curl,websocketpp,pocketsphinx,sphinxbase,mpi,SFML,CUDA(Seperate build file),boost and opencv3

# Flag Explantion
CUDA - This adds CUDA accelerated functions

OPENCL - This adds OPENCL accelerated functions

ALIVE - This is the flag used for to build project ALIVE support

ALL - This builds all features

RFID - Adds RFID support via ardunio mircocontroller

DEBUG - This adds Verbose functions to Lara

MOTOR - This adds support to drive DC motors via ardunio mircocontroller

FOUNDER - Founder edition has support for CAD as well as project ALIVE functions,at this time
___
Custom Compiler Toolchain at:


Pre-built(weekly builds,possibly unstable):
https://drive.google.com/open?id=0ByLm512z8MOiZURjcEJxazc3YWM

# Build Status
Windows:PASS

LINUX:PASS

  Debian:PASS

  GhostOS:Pending
  
  CentOS:Pending
  
  OpenSUSE:Pending

MacOSX:Pending

Raspbian:PASS

# Run Status
Windows:PASS

LINUX:PASS
  
  - Debian:PASS
  
  - GhostOS:Pending
  
  - CentOS:Pending
  
  - OpenSUSE:Pending

MacOSX:Pending

Raspbian :PASS

# Lara Android Companion App @:

https://github.com/watchdog1023/Lara-AI-Android-App

# Note
Python3 with pip is requied to make Lara

To use voice rec please pass "-hmm model/en-us/en-us -lm model/en-us/en-us.lm.bin -dict model/en-us/cmudict-en-us.dict" to lara program

# Support
If you want to help support this project please donate:

BTC:14ubfeivC8GTE8FUr9gFfmSugmKVJQwtxL
