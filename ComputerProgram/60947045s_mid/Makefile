all: 1.o 2.o 3.o 4.o 5.o

1.o:
	gcc -o mid01 mid01.c
2.o:
	gcc -c binp.c
	gcc -c mid02.c
	gcc -o mid02 mid02.o binp.o -lm
3.o:
	gcc -o mid03 mid03.c
4.o:
	gcc -o mid04 mid04.c
5.o:
	gcc -c triangle.c
	gcc -c mid05.c
	gcc -o mid05 mid05.o triangle.o -lm
clean:
