#include <stdio.h>
#include <unistd.h>
int count;
int main(void){
	int pid;
	count =0;	
	for(int i=0; i<4; i++)
	{
		fork();
		count ++;
		//pid = wait();	
		printf("process level %d\n", i);	
	}
	printf("%d threads\n", count);
	return 0;
}
