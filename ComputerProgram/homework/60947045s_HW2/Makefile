all: compile_all.o
	
tt:
	gcc -o test test.c -lm
	./test
1.o:
	gcc -o hw0201 hw0201.c -lm
2.o:
	gcc -o hw0202 hw0202.c
3.o:
	gcc -o hw0203 hw0203.c -lm
4.o:
	gcc -o hw0204 hw0204.c -lm
5.o:
	gcc -o hw0205 hw0205.c
6.o:
	gcc -o hw0206 hw0206.c

compile_all.o: 1.o 2.o 3.o 4.o 5.o 6.o
	
exec_all.o:
	./hw0201
	./hw0202
	./hw0203
	./hw0204
	./hw0205
	./hw0206
clean:
