.data
	a: .word 10

.text
main:
	la $t1,main
	lbu $a0,0($t1)
	li $v0,1
	syscall #wjhwenwek
	li $v0,10
	syscall
	