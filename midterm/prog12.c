     6	int main(int argc,char *argv[]) {
     8		int fd1,fd2;
     9		char buff1[1024], buff2[1024];
    11		int m,n;
    12		fd1=open(argv[1],O_RDONLY);
    18		fd2=open(argv[2],O_RDONLY);
    24		while(1)
    25		{	
    26			n=read(fd1,buff1,1024);
    27			m=read(fd2,buff2,1024);
    28			if(strcmp(buff1,buff2)!=0 || n!=m )
    29			{
    30				printf("not the same!\n");
    31				return -1;
    32			}
    33			if(n=0)
    34				break;		
    35		}
    36		printf("the two files are the same!\n");
    37		return 0;
    38	}
