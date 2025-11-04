#include<stdio.h>
#include<unistd.h>


int main()
{
    int pipefds[2];
    int returnstatus;
    int pid;

    char writemessages[2][20]={"hi","Hello"};
    char readmessage[20];

    returnstatus=pipe(pipefds);

    if(returnstatus ==-1)
    {
        printf("Unable to create a pipe\n");
        return 1;
    }

    pid =fork();
    if(pid==0)
    {
        read(pipefds[0],readmessage,sizeof(readmessage));
        printf("Child process  - reading from pipe message = %s\n",readmessage);
        read(pipefds[0],readmessage,sizeof(readmessage));
        printf("Child process  - reading from pipe message = %s\n",readmessage);
    }
    else
    {
        printf("parent process  - sending to pipe message = %s\n",writemessages[0]);
       write(pipefds[1],writemessages[0],sizeof(writemessages[0]));

        printf("parent process  - sending to pipe message = %s\n",writemessages[1]);
        write(pipefds[1],writemessages[1],sizeof(writemessages[1]));

    }
}