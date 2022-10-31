all: 1.o 2.o 3.o 4-1.o 4-2.o 5.o

1.o:
	gcc -c 1/myfunc.c -o 1/myfunc.o
	gcc -c hw0301.c
	gcc -o hw0301 hw0301.o 1/myfunc.o -lm
2.o:
	gcc -c 2/mystddev.c -o 2/mystddev.o
	gcc -c hw0302.c
	gcc -o hw0302 hw0302.o 2/mystddev.o -lm
3.o:
	gcc -c 3/equ_res.c -o 3/equ_res.o
	gcc -c hw0303.c
	gcc -o hw0303 hw0303.o 3/equ_res.o
4-1.o:
	gcc -c 4/hanoi.c -o 4/hanoi.o
	gcc -c hw0304-1.c
	gcc -o hw0304-1 hw0304-1.o 4/hanoi.o -lm
4-2.o:
	gcc -c 4/hanoi.c -o 4/hanoi.o
	gcc -c hw0304-2.c
	gcc -o hw0304-2 hw0304-2.o 4/hanoi.o -lm
5.o:
	gcc -o hw0305 hw0305.c smallten.c logic.c
clean:
	 
