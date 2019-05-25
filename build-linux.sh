#!/bin/bash
function pause () {
   read -p "$*"
}
which yum && {
     echo centos;
     yum group install "Development Tools";
     yum install kernel-devel;
     if [ ! -e /usr/bin/g++ ];
     then yum install gcc-c++;
     fi;
     if [ ! -e /usr/bin/wget ];
     then yum install wget;
     fi;
     if [ ! -e /usr/bin/mpic++ ];
     then wget -c http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.xz;
     tar xfv autoconf-2.69.tar.xz;
     cd autoconf-2.69/;
     ./configure;
     make;
     sudo make install;
     cd ..;
     wget -c http://ftp.gnu.org/gnu/automake/automake-1.16.1.tar.gz;
     tar xfv automake-1.16.1.tar.gz;
     cd autmake-1.16.1;
     ./configure;
     make;
     sudo make install;
     cd ..;
     wget -c http://www.mpich.org/static/downloads/3.3/mpich-3.3.tar.gz;
     tar xfv mpich-3.3.tar.gz;
     cd mpich-3.3/;
     ./autogen.sh;
     ./configure;
     make;
     sudo make install;
     cd ..;
     fi;
     #if[ ! -e /usr/bin/python3 ];
     #then #yum install https://centos7.iuscommunity.org/ius-release.rpm;
     #yum install python36u;
     #fi;
     #if[ ! -e /usr/bin/pip3];
     #then yum -y install python36u-pip;
     #ln -sf /usr/bin/pip3.6 /usr/bin/pip3;
     #fi;
     return;
     }

     which zypper && {
     echo opensuse;
     zypper update;
     zypper install gcc-c++
     return;
     }
     which apt-get && {
     echo debian;
     if [ ! -e /usr/bin/mpic++ ]; then
        sudo apt-get install libmpich-dev;
     fi;
     if [ ! -e /usr/bin/python3 ]; then
        sudo apt-get install python3;
     fi;
     if [ ! -e /usr/bin/pip3 ]; then
        sudo apt-get install python3-pip;
     fi;
     if [ ! -e /usr/bin/g++ ]; then
        sudo apt-get install build-essential make;
     fi
     if [ ! -e /usr/bin/swig ]; then
        sudo apt-get install swig;
     fi
     sudo apt-get install libboost-dev libsfml-dev libtesseract-dev;
     }
     which dnf && {
     echo Fedora;
     return;
     }
if [ ! -e opencv-3.4.3/ ]; then 
   wget -c https://github.com/opencv/opencv/archive/3.4.3.zip
   wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O contrib-343.zip
   unzip -qq 3.4.3.zip
   unzip -qq contrib-343.zip
   cd opencv-3.4.3/
   mv -v ../opencv_contrib-3.4.3/* .
   mkdir build
   cd build
   cmake -quiet ..
   make -j4
   sudo make install
   cd ../..
else
   cd opencv-3.4.3/
   cd build
   sudo make install
   cd ../..
fi
if [ ! -e chilkat-9.5.0-x86_64-linux-gcc/ ]; then
   wget -c https://chilkatdownload.com/9.5.0.78/chilkat-9.5.0-x86_64-linux-gcc.tar.gz
   tar xf chilkat-9.5.0-x86_64-linux-gcc.tar.gz
   sudo mv -v chilkat-9.5.0-x86_64-linux-gcc/include chilkat-9.5.0-x86_64-linux-gcc/chilkat
fi
if [ ! -e mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/ ]; then
   wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
   tar xf mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
fi
if [ ! -e libtensorflow-cpu-linux-x86_64-1.13.1/ ]; then
   wget -c https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz
   mkdir libtensorflow-cpu-linux-x86_64-1.13.1
   tar xf libtensorflow-cpu-linux-x86_64-1.13.1.tar.gz -C libtensorflow-cpu-linux-x86_64-1.13.1
fi
if [ ! -e sphinxbase-5prealpha/ ]; then
   wget -c https://tenet.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
   tar xf sphinxbase-5prealpha.tar.gz
   cd sphinxbase-5prealpha
   ./configure
   make
   sudo make install
   cd ..
else
   cd sphinxbase-5prealpha
   sudo make install
   cd ..
fi
if [ ! -e pocketsphinx-5prealpha/ ]; then
   wget -c https://tenet.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
   tar xf pocketsphinx-5prealpha.tar.gz
   cd pocketsphinx-5prealpha
   ./configure
   make
   sudo make install
   cd ..
else
   cd pocketsphinx-5prealpha
   sudo make install
   cd ..
fi
if [  -e /usr/bin/pip2 ]; then
   sudo -H pip install --upgrade pip
   sudo -H pip install setuptools
   sudo -H pip install pyscreenshot selenium datetime 
fi
if [  -e /usr/bin/pip3 ]; then
   sudo -H pip3 install --upgrade pip
   sudo -H pip3 install setuptools
   sudo -H pip3 install pyscreenshot selenium datetime
fi
sudo rm /usr/local/include/sphinxbase/prim_type.h

echo "#ifndef _LIBUTIL_PRIM_TYPE_H_" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define _LIBUTIL_PRIM_TYPE_H_" >> /usr/local/include/sphinxbase/prim_type.h

echo "/**" >> /usr/local/include/sphinxbase/prim_type.h
echo "* @file prim_type.h" >> /usr/local/include/sphinxbase/prim_type.h
echo "* @brief Basic type definitions used in Sphinx. " >> /usr/local/include/sphinxbase/prim_type.h
echo "*/" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#ifdef __cplusplus" >> /usr/local/include/sphinxbase/prim_type.h
echo "extern "C" {" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "#if 0" >> /usr/local/include/sphinxbase/prim_type.h
echo "} /* Fool Emacs into not indenting things. */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#include <sphinx_config.h>" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/* Define some things for VisualDSP++ */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#if defined(__ADSPBLACKFIN__) && !defined(__GNUC__)" >> /usr/local/include/sphinxbase/prim_type.h
echo "# ifndef HAVE_LONG_LONG" >> /usr/local/include/sphinxbase/prim_type.h
echo "#  define HAVE_LONG_LONG" >> /usr/local/include/sphinxbase/prim_type.h
echo "# endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "# ifndef ssize_t" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef signed int ssize_t;" >> /usr/local/include/sphinxbase/prim_type.h
echo "# endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "# define SIZEOF_LONG_LONG 8" >> /usr/local/include/sphinxbase/prim_type.h
echo "# define __BIGSTACKVARIABLE__ static" >> /usr/local/include/sphinxbase/prim_type.h
echo "#else /* Not VisualDSP++ */" >> /usr/local/include/sphinxbase/prim_type.h
echo "# define __BIGSTACKVARIABLE__" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/**" >> /usr/local/include/sphinxbase/prim_type.h
echo "* Union of basic types." >> /usr/local/include/sphinxbase/prim_type.h
echo "*/" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef union anytype_s {" >> /usr/local/include/sphinxbase/prim_type.h
echo "void *ptr;" >> /usr/local/include/sphinxbase/prim_type.h
echo "long i;" >> /usr/local/include/sphinxbase/prim_type.h
echo "unsigned long ui;" >> /usr/local/include/sphinxbase/prim_type.h
echo "double fl;" >> /usr/local/include/sphinxbase/prim_type.h
echo "} anytype_t;" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/*" >> /usr/local/include/sphinxbase/prim_type.h
echo "* Assume P64 or LP64.  If you need to port this to a DSP, let us know." >> /usr/local/include/sphinxbase/prim_type.h
echo "*/" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef int		int32;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef short		int16;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef signed char	int8;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef unsigned int	uint32;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef unsigned short	uint16;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef unsigned char	uint8;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef float		float32;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef double		float64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "#if defined(_MSC_VER)" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef __int64	         int64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef unsigned __int64 uint64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "#elif defined(HAVE_LONG_LONG) && (SIZEOF_LONG_LONG == 8)" >> /usr/local/include/sphinxbase/prim_type.h
echo "//typedef long long	   int64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef unsigned long long uint64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "#else /* !HAVE_LONG_LONG && SIZEOF_LONG_LONG == 8 */" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef double          int64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "typedef double          uint64;" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif /* !HAVE_LONG_LONG && SIZEOF_LONG_LONG == 8 */" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#ifndef TRUE" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define TRUE 1" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "#ifndef FALSE" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define FALSE 0" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#ifndef NULL" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define NULL (void *)0" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/* These really ought to come from <limits.h>, but not everybody has that. */" >> /usr/local/include/sphinxbase/prim_type.h
echo "/* Useful constants */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_INT32		((int32) 0x7fffffff)" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_INT16		((int16) 0x00007fff)" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_INT8		((int8)  0x0000007f)" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_NEG_INT32		((int32) 0x80000000" >> /usr/local/include/sphinxbase/prim_type.h)
echo "#define MAX_NEG_INT16		((int16) 0xffff8000)" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_NEG_INT8		((int8)  0xffffff80)" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_UINT32		((uint32) 0xffffffff)" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_UINT16		((uint16) 0x0000ffff)" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_UINT8		((uint8)  0x000000ff)" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/* The following are approximate; IEEE floating point standards might quibble! */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_POS_FLOAT32		3.4e+38f" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_POS_FLOAT32		1.2e-38f	/* But not 0 */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_POS_FLOAT64		1.8e+307" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_POS_FLOAT64		2.2e-308" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_IEEE_NORM_POS_FLOAT32        3.4e+38f" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_IEEE_NORM_POS_FLOAT32        1.2e-38f" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_IEEE_NORM_NEG_FLOAT32       -3.4e+38f" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MAX_IEEE_NORM_POS_FLOAT64        1.8e+307" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_IEEE_NORM_POS_FLOAT64        2.2e-308" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_IEEE_NORM_NEG_FLOAT64       -1.8e+307" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "/* Will the following really work?? */" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_NEG_FLOAT32		((float32) (-MIN_POS_FLOAT32))" >> /usr/local/include/sphinxbase/prim_type.h
echo "#define MIN_NEG_FLOAT64		((float64) (-MIN_POS_FLOAT64))" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#ifdef __cplusplus" >> /usr/local/include/sphinxbase/prim_type.h
echo "}" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h
echo "" >> /usr/local/include/sphinxbase/prim_type.h
echo "#endif" >> /usr/local/include/sphinxbase/prim_type.h

mpic++ -fpermissive -std=c++14 -I"/usr/local/include/pocketsphinx/" -I"/usr/local/include/sphinxbase/" -I"./include/" -I"libtensorflow-cpu-linux-x86_64-1.13.1/include" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/jdbc" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/mysql" -I"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/mysqlx" -I"./chilkat-9.5.0-x86_64-linux-gcc/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors 2> LaraC.txt 
g++ -time -std=c++14 -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
g++ -time -std=c++14 -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
g++ -time -std=c++14 -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
g++ -time -std=c++14 -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
g++ -time -std=c++14 -L"./mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib64" -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -L"./chilkat-9.5.0-x86_64-linux-gcc/lib" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad 2> LaraB.txt
if [ ! -e ./lara ];then
    echo "Code Not Sane";
    echo "========================Build Stage Output========================================"
    cat LaraB.txt
    echo "========================Compile Stage Output======================================"
    cat LaraC.txt
    echo "=================================================================================="
    if [ $TRAVIS_BRANCH != "master" ]; then
      pause 'Press [Enter] key to continue...'
    else
      exit 1;
    fi
else
    rm -vr lara *.o
    echo "Code is Sane";
    if [ $TRAVIS_BRANCH != "master" ]; then
      pause 'Press [Enter] key to continue...'
    fi
    mpic++ -v -fpermissive -std=c++14 -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux/" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/" -c Lara.cpp -o Lara.o -Wfatal-errors
    g++ -v -time -c include/IRC/Thread.cpp -o Thread.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCClient.cpp -o IRCClient.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCSocket.cpp -o IRCSocket.o -Wfatal-errors
    g++ -v -time -c include/IRC/IRCHandler.cpp -o IRCHandler.o -Wfatal-errors
    g++ -v -time -c include/qr_code/BitBuffer.cpp -o Bitbuffer.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrCode.cpp -o QrCode.o -Wfatal-errors
    g++ -v -time -c include/qr_code/QrSegment.cpp -o QrSegment.o -Wfatal-errors
    g++ -v -time -fpermissive -c include/Emotions.cpp -o Emotions.o -Wfatal-errors
    g++ -time -L"/usr/lib/jvm/java-1.5.0-gcj-6-amd64/lib/" -o lara Lara.o Thread.o IRCClient.o  Bitbuffer.o QrCode.o QrSegment.o Emotions.o IRCSocket.o IRCHandler.o -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lpthread -lsfml-audio -lsfml-network  -lsfml-system -lcurl -lboost_system -lboost_thread -lboost_serialization -lmpi -lpython3.5m -lchilkat-9.5.0 -lmpi_cxx -lncurses -lpocketsphinx -lsphinxbase -lsphinxad
fi
