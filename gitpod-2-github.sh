#!/bin/bash
#cleaning the source tree
rm -vr opencv-3.4.3/
rm -vr opencv_contrib-3.4.3/
rm -vr 3.4.3.zip
rm -vr contrib-343.zip
rm -vr pocketsphinx-5prealpha*
rm -vr sphinxbase-5prealpha*
rm -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit*
yes | rm -vr libtensorflow-cpu-linux-x86_64-1.13.1*
yes | rm -vr libtitan
yes | rm -vr jsoncpp
yes | rm -vr assets/
rm -vr data/obj_detect/
rm -vr *.o
if [ -e lara-alive ]; then
    rm -vr lara-alive
fi
if [ -e lara ]; then
    rm -vr lara  
fi
#rm -vr data/
rm -vr LaraB.txt LaraC.txt
clear
echo "Ready to push!"
