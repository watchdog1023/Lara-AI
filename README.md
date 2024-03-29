# Lara-AI
[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/watchdog1023/Lara-AI) 
[![Build Status](https://app.travis-ci.com/watchdog1023/Lara-AI.svg?branch=master)](https://app.travis-ci.com/watchdog1023/Lara-AI)
[![CodeFactor](https://www.codefactor.io/repository/github/watchdog1023/lara-ai/badge/master)](https://www.codefactor.io/repository/github/watchdog1023/lara-ai/overview/master)

compile with -fpermissive -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors flags 

NB:Linux users should use mpic++ to compile 

# Windows Specify 
Build with -static-libgcc -static-libstdc++ flags at start and -lgdi32 -lcrypt32 -lws2_32 -lwsock32 -ldnsapi -lwinmm -lwininet -lmingw32 -lopencv_core340.dll -lopencv_highgui340.dll -lopencv_imgproc340.dll -lopencv_imgcodecs340.dll -lopencv_videoio340.dll -lopencv_video340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread -lpython36 -lzbar.dll -lsfml-audio -lsfml-network -lsfml-main -lsfml-system -lcurl -lbitcoinapi -lcryptopp -ljsoncpp -ltesseract400.dll -lleptonica-1.75.0.dll -lpocketsphinx -lsphinxbase flags at end(include all the .o files when building)

# Linux Specify
Build with -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase flags at end(include all the .o files when building)

# Libs
The Libaries used are:
  - termcolor(https://github.com/ikalnytskyi/termcolor)
  - qrcodegen
  - zbar
  - MYSQL connector++
  - SQLite3
  - tesseract-ocr
  - leptonica
  - curl
  - websocketpp
  - pocketsphinx
  - sphinxbase
  - mpi
  - SFML
  - CUDA(Seperate build file)
  - boost
  - opencv3
  - JSONcpp(https://github.com/open-source-parsers/jsoncpp)
  - HTTPSRequest(https://github.com/elnormous/HTTPRequest

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

  - Debian:PASS

  - GhostOS:Pending
  
  - CentOS:Pending
  
  - OpenSUSE:Pending

MacOSX:Failing

Raspbian:PASS

# Run Status
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

Windows:PASS

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

LINUX:PASS
  
  ![Debian](https://img.shields.io/badge/Debian-D70A53?style=for-the-badge&logo=debian&logoColor=white)
  
  - Debian:PASS
  
  - GhostOS:Pending
  
  ![Cent OS](https://img.shields.io/badge/cent%20os-002260?style=for-the-badge&logo=centos&logoColor=F0F0F0)

  - CentOS:Pending
  
  - OpenSUSE:Pending

![Mac OS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)

MacOSX:Failing

![Raspberry Pi](https://img.shields.io/badge/-RaspberryPi-C51A4A?style=for-the-badge&logo=Raspberry-Pi)

Raspbian :PASS

# Lara Android Companion App @:

![Android](https://img.shields.io/badge/Android-3DDC84?style=for-the-badge&logo=android&logoColor=white)

https://github.com/watchdog1023/Lara-AI-Android-App

# Languages Used

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)

# Note
Python3 with pip is requied to make Lara

To use voice rec please pass "-hmm model/en-us/en-us -lm model/en-us/en-us.lm.bin -dict model/en-us/cmudict-en-us.dict" to lara program

# Coming Soon

![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)

# Family Tree
Oldest Sister - Lexa-AI (https://github.com/watchdog1023/Lexa-AI)

Second Oldest Sister - Raven-AI (https://github.com/watchdog1023/Raven-AI)

Youngest Sister - Ciri-AI (https://github.com/watchdog1023/Ciri-AI)

# Support
If you want to help support this project please donate:

![Bitcoin](https://img.shields.io/badge/Bitcoin-000?style=for-the-badge&logo=bitcoin&logoColor=white)
BTC:14ubfeivC8GTE8FUr9gFfmSugmKVJQwtxL
