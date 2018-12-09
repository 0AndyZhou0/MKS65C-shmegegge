all : shmegegge.o
	gcc shmegegge.o

run : ./a.out
	./a.out

shmegegge.o : shmegegge.c
	gcc -c shmegegge.c

clean :
	rm ./a.out *.o

fix : shmegegge.c
	gcc -g shmegegge.c
	gdb ./a.out
