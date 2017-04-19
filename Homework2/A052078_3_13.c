#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int a1=0, a2=1 // the first two variables of the sequence
	int tmp, i; // third element of the sequence

	printf("Enter the number of a Fibonacci Sequence:\n");
	scanf("%d", &i);

	while(i<=0)
	{
		printf("Please Enter a positive number\n");
		scanf("%d", &i);
	}

	pid_t pid = fork();

	if(pid == 0)	// child process
	{
		printf("The Child Process is making Sequence\n");
		while(i > 0)
		{
			tmp = a1 + a2;
			printf(" %d ",tmp);
			a1 = a2;
			a2 = tmp; 
			i--;
		}
		printf("\nEnd of Child Process");
	}
	else	// parent process
	{
		printf("Parent is waiting\n");
		wait(NULL);
		printf("Parent Ends\n");
	}
return 0;


}
