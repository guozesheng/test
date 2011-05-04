CFLAG = -Wall -c -fPIC
LDFLAG = -shared
INC = -Iinc
LIB = -L. -ltest
src = main.c
libsrc = $(wildcard test/*.c)
obj = $(patsubst %.c, %.o, $(libsrc))
CC = gcc
target = libtest.so

main:all
	$(CC) $(src) $(LIB) $(INC)
all:$(obj)
	$(CC) $(obj) $(LDFLAG) -o $(target)
%.o:%.c
	$(CC) $(CFLAG) -o $@ $<
.PHONY:clean
clean:
	rm -f *.o
	rm -f *.so
	rm -f a.out
