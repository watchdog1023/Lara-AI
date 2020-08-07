FROM gitpod/workspace-full

USER root
RUN apt update
RUN apt upgrade -y
#Grabbing Deps
RUN apt-get install libmpich-dev python3 python3-pip build-essential make swig libboost-all-dev libsfml-dev libtesseract-dev bash splint shellcheck -y
#get packager
RUN apt-get install checkinstall -y
RUN pip3 install cpplint requests
USER gitpod
# Install custom tools, runtime, etc. using apt-get
# For example, the command below would install "bastet" - a command line tetris clone:
#
# RUN sudo apt-get -q update && #     sudo apt-get install -yq bastet && #     sudo rm -rf /var/lib/apt/lists/*
#
# More information: https://www.gitpod.io/docs/42_config_docker/
