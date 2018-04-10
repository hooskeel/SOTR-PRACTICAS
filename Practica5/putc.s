.code32		# Use 32bit mode.
.section .text		# Code must resides in the ".text" in GCC.
.globl putc		# Declare putc() as a public function.
putc:
pushl %ebp		# Remember %ebp.
movl %esp,%ebp          # Prepare my stack frame.
			# Now, (%ebp) points saved %ebp,
			# and 4(%ebp) points return address.
# [ NOTE ] We must preserve registers except %eax, %ecx, and %edx.
pushl %ebx		# Save EBX.
# [ NOTE ] 1st argument appears in 8(%ebp), and 2nd 12(%ebp) ...

movl 12(%ebp),%eax	# Get character code. (2nd argument)
movb %al,(msgbuf)	# And save it.
movl $1,%edx		# Set character count.
movl $msgbuf,%ecx	# Set buffer pointer.
#movl $1,%ebx		# Set STDOUT.
movl 8(%ebp),%ebx	# Get file descriptor and set STDOUT. (1st argument)
movl $4,%eax		# Call sys_write().
int $0x80

popl %ebx                      # Recover %ebx.

movl %ebp,%esp           # Perform %esp=%ebp
popl %ebp                      # and EBP=pop().
ret

# [ NOTE ] Storage area for the variables starts from here.
.section .data		# Variables must reside in the ".data" in GCC.
msgbuf:
.byte 0			# Message buffer.

