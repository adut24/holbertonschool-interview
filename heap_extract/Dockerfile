FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y gcc-4.8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 100

RUN apt-get install -y valgrind

WORKDIR /app

COPY *.c /app/
COPY binary_trees.h /app/
COPY libheap.a /app/

RUN gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract \
    0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap

CMD ["valgrind", "./0-heap_extract"]