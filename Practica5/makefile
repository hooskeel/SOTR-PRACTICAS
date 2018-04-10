AS=as
CC=gcc
LD=ld

ASFLAGS=--32
CFLAGS=-fno-stack-protector -fno-builtin -m32 -c
LDFLAGS=-m elf_i386 -s -e main 

BIN=testprintf

all:$(BIN)

$(BIN):TestPrintf.o salir.o putc.o printf.o
	$(LD) $(LDFLAGS) $^ -o $@

TestPrintf.o:TestPrintf.c
	$(CC) $(CFLAGS) $< -o $@

printf.o:printf.c
	$(CC) $(CFLAGS) $< -o $@

salir.o:salir.s
	$(AS) $(ASFLAGS) $< -o $@

putc.o:putc.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -v *.o $(BIN)
