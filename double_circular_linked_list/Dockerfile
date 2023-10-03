FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y gcc-4.8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 100

WORKDIR /app

COPY *.c /app/
COPY list.h /app/

RUN gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c -o program

