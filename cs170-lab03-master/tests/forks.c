
#include <stdio.h>

void print_new_fork_info(int fork_num, int pid) {
	/* Purposefully ignoring > 0, because I just want to see the new processes */
	if (pid == 0) {
	       	printf("After fork #%d: My parent is %d and I'm the child with pid %d!\n", fork_num, getppid(), getpid());
	} else if (pid < 0) {
		printf("Process %d failed at fork #%d\n", getpid(), fork_num);
	}
}

int main ()
{
	int pid;

	printf("We begin with one single process with parent pid %d and pid of %d\n", getppid(), getpid());

	pid = fork();
	print_new_fork_info(1, pid);

	pid = fork();
	print_new_fork_info(2, pid);

	pid = fork();
	print_new_fork_info(3, pid);

	pid = fork();
	print_new_fork_info(4, pid);

	while(1) {
		sbrk(0); // Until you've added time-slicing, we need a way to trigger your scheduler so other threads can run. Making a system call is one way
	}
}