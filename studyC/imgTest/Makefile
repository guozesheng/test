# This is for imgTest

src = $(wildcard *.c)
para = -o main -Wall -ljpeg
img = test.jpg

main:$(src)
	gcc $(src) $(para)
clean:
	rm -rf main
	rm -rf *.o
	rm -rf ~*
run:
	./main $(img)
