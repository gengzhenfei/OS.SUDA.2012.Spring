#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 4096
int main(int argc, char* argv[])
{
    int n;
    char buf1[BUFFSIZE];
    char buf2[BUFFSIZE];

    if (argc != 3) {
printf("argc!=3\n");
        // Usage Information: 
        exit(1);
    }
    int fin  = open(argv[1], O_RDONLY);

   if(fin==-1)
{
printf("can not open the file!\n");
exit(1);
    // errror detecting
}

    int fout = open(argv[2], O_RDONLY);

  if(fout==-1)
{printf("can not the file!\n");
exit(1);
   // errror detecting
}

  if(read(fin,buf1,BUFFSIZE)!=read(fout,buf2,BUFFSIZE)) ///////////// WHERE IS THE LOOP???
{
     printf("NOT SAME!");
    exit(1);
 // errror detecting
}
 else 
{
   if(strcmp(buf1,buf2)==0)
{printf("SAME!");
exit(1);
}
   else {printf("NOT SAME!");
exit(1);
// errror detecting
}
}
    close(fout);
    close(fin);
    return 0;
}
