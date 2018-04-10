.section .data

.section .text
.globl salir
salir:
pushl %ebp
movl %esp,%ebp
movl 8(%ebp),%ebx                  # lee el \unico argumento de esta funci\on

movl $1,%eax	                         # this is the linux kernel command 
                                                  # number (system call) for exiting
                                                  # a program
int $0x80                                   # this wakes up the kernel to run
		                        # the exit command
