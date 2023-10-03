FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y gcc-4.8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 100

RUN apt-get install -y valgrind

WORKDIR /app

COPY *.c /app/
COPY holberton.h /app/

RUN gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
