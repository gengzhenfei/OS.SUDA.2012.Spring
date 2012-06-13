#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(int argc, char* argv[])
{
	int n1,n2;
	char buf1[BUFFSIZE];
	char buf2[BUFFSIZE];
	if (argc != 3) {
		printf("There should be three varibles:file_name(which is used to be copyed) file_name(new file)\n");// Usage Information: 
		exit(1);
	}
	//printf("%d\n", argc);
	int fin1  = open(argv[1], O_RDONLY);
	if(fin1<=0)// error detecting
	{
    		printf("Open the first file error!\nPlease check the file_name and try again!\n");
		exit(1);
	}

	int fin2  = open(argv[2], O_RDONLY);
	if(fin2<=0)// error detecting
	{
    		printf("Open the second file error!\nPlease check the file_name and try again!\n");
		exit(1);
	}

	do 
	{
		n1=read(fin1, buf1, BUFFSIZE);
		n2=read(fin2, buf2, BUFFSIZE);
		//printf("%d",n1);
		if( n1>0 && (strcmp(buf1,buf2)) )
		{
			printf("In fact,they are different files\n");
			return 0;
		}
		else if(n1==0)   ////////// file1: 0 bytes, file2: 1 byte
		{
			printf("Congratulations,they are the same files\n");
			return 0;
		}
		else if (n1 < 0)
		{
		   	printf("Sorry,there is something wrong in the process!");
		   	exit(-1); // error message
		}
	}while(n1==n2); ////////// do ... while LOOP !!
    close(fin1);
    close(fin2);
    return 0;
}
