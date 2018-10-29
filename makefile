run: all
	./randomfile
	rm randomfile
	rm *.txt

all:
	gcc randomfile.c -o randomfile

random.o: randomfile.c
	gcc -c randomfile.c
