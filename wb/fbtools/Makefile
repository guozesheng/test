# This is for chess game

src=$(wildcard *.c)
#patsubst rename
#obj=$(patsubst %.c.bak, %.o, $(src))
para=-o main -Wall -lm

main:$(src)
	gcc $(src) $(para)
clean:
	rm -rf main
	rm -rf *.o
	rm -rf ~*
run:
	./main
