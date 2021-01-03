FROM debian:bullseye-backports

RUN export PREBUILD=YES
RUN sudo apt update
RUN sudo apt install g++ gcc -y
RUN apt-get install curl git wget rsync sudo -y
RUN sudo apt-get install dos2unix bash tree locate -y
RUN sudo apt-get install libboost-all-dev libsfml-dev libtesseract-dev libmpich-dev libpulse-dev libopenexr24 -y
RUN sudo updatedb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/jsoncpp_3.13.2-1_amd64.deb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/libtitan_1.2-1_amd64.deb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/sphinxbase_5prealpha-1_amd64.deb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/pocketsphinx_5prealpha-1_amd64.deb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/sqlite3_3330000-1_amd64.deb
RUN wget -q -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/opencv-3.4.3_amd64.deb
RUN sudo dpkg -i jsoncpp_3.13.2-1_amd64.deb
RUN sudo dpkg -i libtitan_1.2-1_amd64.deb
RUN sudo dpkg -i sphinxbase_5prealpha-1_amd64.deb
RUN sudo dpkg -i pocketsphinx_5prealpha-1_amd64.deb
RUN sudo dpkg -i sqlite3_3330000-1_amd64.deb
RUN sudo dpkg -i opencv-3.4.3_amd64.deb
RUN sudo rm *.deb
RUN sudo apt clean 
RUN sudo ldconfig
RUN cd /root/ && git clone https://github.com/watchdog1023/Lara-AI.git
RUN cd /root/ && wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz && tar xfv mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz && mv -v mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/jdbc/* mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/ && mv -v mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib64/ mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib/ && rsync -a  mysql-*/* /usr/local/ && rm -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit*
RUN mkdir /usr/local/include/jsoncpp && mv -v /usr/local/include/json/ /usr/local/include/jsoncpp/
RUN cp /root/Lara-AI/include/prim_type.h /usr/local/include/sphinxbase/prim_type.h
RUN wget https://pjreddie.com/media/files/yolov3.weights -O yolov3.weights
RUN wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg?raw=true -O yolov3.cfg
RUN wget https://github.com/pjreddie/darknet/blob/master/data/coco.names?raw=true -O coco.names
RUN mkdir -p /root/Lara-AI/data/obj_detect
RUN mv -v yolov3.* /root/Lara-AI/data/obj_detect/
RUN mv -v coco.names /root/Lara-AI/data/obj_detect/
RUN dos2unix /root/Lara-AI/build-linux.sh
RUN chmod -v 777 /root/Lara-AI/build-linux.sh
RUN cd /root/Lara-AI && ./build-linux.sh
CMD ["/bin/bash"]