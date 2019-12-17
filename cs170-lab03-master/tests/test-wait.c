#if 0 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#endif

int main()
{
	int status;
	int pid = fork();
	if (pid > 0) {
		int waited_pid = wait(&status);
		while (waited_pid != pid) {
		}
		//printf("parent done, child's status should be 42: %d\n", WEXITSTATUS(status));
		printf("parent done, child's status was %d\n", status);
	} else {
		printf("child done\n");
		exit(42);
	}
}
