FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y gcc-4.8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 100

RUN apt-get install -y valgrind

WORKDIR /app

COPY *.c /app/
COPY holberton.h /app/

RUN gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul

CMD ["./mul", "235234693269436436223446526546334576437634765378653875874687649698659586695898579", "0"]
