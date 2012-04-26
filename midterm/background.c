#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 4096

int
main(void)
{
	char	buf[MAXLINE];	
	pid_t	pid;
	int		status;
    int     background;

	printf("%% ");	

	while (fgets(buf, MAXLINE, stdin) != NULL) {
        background = 0;
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */

        if (buf[strlen(buf) - 1] == '&') {
            *** //background = 1;
            buf[strlen(buf) - 1] = 0;
        }
        pid = fork();
		if (pid < 0) 
            exit(1);
		else if (pid == 0) {		/* child */
			execlp(buf, buf, (char *)0);
            printf("error: cannot execute your command.\n"); ///// ???
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, background? WNOHANG : 0)) < 0)
            exit(2);

		printf("%% ");
	}
	exit(0);
}
