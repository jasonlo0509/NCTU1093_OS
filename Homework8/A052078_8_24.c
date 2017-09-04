#include "stdio.h"
#define PAGE_SIZE 4096

int main(int argc, char** argv) {
	if(argc<2){
		printf("Enter the virtual address\n");
		return -1;
	}
	unsigned int address = atoi(argv[1]);
    printf("The address %d contains:\n", address);
    unsigned int page_num = address / PAGE_SIZE;
    unsigned int offset = address % PAGE_SIZE;
    printf("page number = %d \n", page_num);
    printf("offset = %d \n", offset);
}