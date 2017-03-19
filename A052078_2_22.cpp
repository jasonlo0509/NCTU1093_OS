# include <iostream>
# include <cstdio>
# include <cstdlib>
using namespace std;


int main()
{
	// Declaration 
 	char src_file[100];
 	char des_file[100];
 	char * buffer;
 	//char buf[BUFSIZ];
 	//long buff_size;
 	size_t size, lSize;
 	int result;

 	// Ask User to input the source and destination file name
 	cout << "Please Type the input file name" << endl;
 	cin >> src_file; 
 	cout << "Please Type the destination file name" << endl;
 	cin >> des_file;
 	
 	// check if there exists source and destination file name
 	FILE* source = fopen(src_file, "r");
 	FILE* destination = fopen(des_file, "w");
 	
 	// if EITHER file don't exist, break and return error message
 	// if BOTH exist then start to read the contents into the buffer
 	if(source == NULL)
 	{
 		cout << "Fail to open source file: " << src_file << endl;
 		exit(-1);
 	}
 	else if (destination == NULL)
 	{
 		cout << "Fail to open destination file: " << des_file << endl;
 		exit(-1);
 	}
 	else
 	{
 		cout << "Copying file from " << src_file << " To " << des_file << endl;
 		
 		// obtain file size
		fseek (source , 0 , SEEK_END);
		lSize = ftell (source);
		rewind (source);
		cout << "file size is " << lSize << endl;

		// allocate memory to contain the whole file
		buffer = (char*) malloc (sizeof(char)*lSize);
  		if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  		// copy the file into the buffer
  		result = fread (buffer,1,lSize,source);
  		if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
  		
  		// write the contents to the destination file
  		fwrite(buffer, 1, result, destination);

  		/* another way to do it using predefined index 
 		while(size)
 		{
 			size = fread(buf, 1, BUFSIZ, source);
 			fwrite(buf, 1, size, destination);
 			
 		}*/

    	fclose(source);
    	fclose(destination);
    	free(buffer);
    	cout << "----Copy finish----" << endl;
 	}
 	return 0;


}