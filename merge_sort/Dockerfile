FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y gcc-4.8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 100

RUN apt-get install -y valgrind

WORKDIR /app

COPY *.c /app/
COPY sort.h /app/

RUN gcc -Wall -Wextra -Werror -pedantic \
    0-main.c 0-merge_sort.c print_array.c -o merge
