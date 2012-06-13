#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd1,fd2;
	char buff1[1024];
	char buff2[1024];
	int m,n;
	fd1=open(argv[1],O_RDONLY);
	if(fd1<0)
	{
		printf("open the first file failed!\n");
		return -1;
	}
	fd2=open(argv[2],O_RDONLY);
	if(fd2<0)
	{
		printf("open the second file failed!\n");
		return -1;
	}
	while(1)
	{	
		n=read(fd1,buff1,1024);
		m=read(fd2,buff2,1024);
		if(strcmp(buff1,buff2)!=0 || n!=m )
		{
			printf("not the same!\n");
			return -1;
		}
		if(n=0)
			break;		
	}
	printf("the two files are the same!\n");
	return 0;
}

