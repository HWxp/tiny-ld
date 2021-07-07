main : elf.o
	cc -o main elf.o

elf.o : elf.c elf.h common.h
	cc -c elf.c

clean:
	rm -rf *.o
