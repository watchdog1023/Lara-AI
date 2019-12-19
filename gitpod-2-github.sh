#cleaning the source tree
rm -vr opencv-3.4.3/
rm -vr opencv_contrib-3.4.3/
rm -vr 3.4.3.zip
rm -vr contrib-343.zip
rm -vr pocketsphinx-5prealpha*
rm -vr sphinxbase-5prealpha*
rm -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit*
yes | rm -vr libtensorflow-cpu-linux-x86_64-1.13.1*
rm -vr chilkat-9.5.0-x86_64-linux-gcc*
rm -vr *.o
rm -vr data/
rm -vr LaraB.txt LaraC.txt
clear
echo "Ready to push!"