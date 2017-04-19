# include <stdlib.h>
# include <stdio.h>
# include <sys/shm.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
#define MAX_SEQUENCE 10

typedef struct{
	long sequence[MAX_SEQUENCE];
	int sequence_size;
}shared_data;


int main(){
	int a1=0, a2=1, tmp, input, i;
	
	printf("Enter the number of a Fibonacci Sequence:\n");
	scanf("%d", &input);

	while(input<=0)
	{
		printf("Please Enter a positive number\n");
		scanf("%d", &input);
	}
	while(input > MAX_SEQUENCE)
	{
		printf("Please Enter a positive number less than %d\n", MAX_SEQUENCE);
		scanf("%d", &input);
	}
	
    int segment_id;	// the id for the shared memory
    segment_id = shmget(IPC_PRIVATE, sizeof(shared_data), S_IRUSR | S_IWUSR);	// allocate a shared memory segment
    
    shared_data *shared_memory = shmat(segment_id, NULL, 0);
    sprintf(shared_memory, "Writing to shared memory");

    pid_t pid = fork(); // create a new process

    if(pid == 0)	// child process
	{
		printf("The Child Process is making Sequence\n");
		shared_memory->sequence[0] = a1; //initialize the first two value
        shared_memory->sequence[1] = a2;
        for (i = 2; i < input; i++){
            tmp = a1+a2;
            shared_memory->sequence[i] = tmp;
            a1 = a2;
            a2 = tmp;
        }
        printf("\nChild ends\n"); 
	}
	else	// parent process
	{
		printf("Parent is waiting\n");
        wait(NULL);
        
        for(i = 0; i < input; i++) {
            printf("%ld ", shared_memory->sequence[i]);
        }
        printf("\nParent ends\n");
	}

    shmdt(shared_memory);	// detatch the memory(referenced from Internet)
    shmctl(segment_id, IPC_RMID, NULL); 	// remove the shared memory

	return 0;
}