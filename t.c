#include <dirent.h>

#include<string.h>

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include <errno.h>
#include <unistd.h>
#define BUFFER 2000
char buf[BUFFER];
typedef struct msgbuf{
long mtype;
char mtext[80];
}message_buf;
int main(int argc, char **argv){
int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;

    key = 10;	
if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }
pid_t pid;
   	pid = fork();
	if(pid==0){
printf("child %d\n",getpid());
int t=1;
printf("child 1\n");
while(t!=0){
printf("child 2\n");
msgrcv(msqid, &sbuf, 80, 2, 0);
printf("child 3\n");
if(sbuf.mtype!=0){
int  f1, f2, n;
char s1[80];
printf("child 4\n");

strcpy(s1, sbuf.mtext);
msgrcv(msqid, &sbuf, 80, 2, 0);
char s2[80];
printf("child 5\n");
strcpy(s2, sbuf.mtext);
if ((f1 = open(s1, O_RDONLY)) == -1)
		fprintf(stderr,"1");
	if ((f2= open(s2, O_WRONLY |O_CREAT, S_IRUSR | S_IWUSR )) == -1)

//fprintf(stderr, "4");
while ((n = read(f1, buf, BUFFER)) > 0)
if (write(f2, buf, n) != n)

close (f1);
close(f2);
}
else t=0;
}

  }
else{
printf("ded %d \n",getpid());
DIR *dir;
    struct dirent *entry;
 while ( (entry = readdir(dir)) != NULL) {
	char s1[strlen(argv[1])+strlen(entry->d_name)+1];
	char s2[strlen(argv[2])+strlen(entry->d_name)+1];
	strcpy(s1, argv[1]);
	strcat(s1, entry->d_name);
	strcpy(s2, argv[2]);
	strcat(s2, entry->d_name);
	sbuf.mtype = 2;
	
strcpy(sbuf.mtext, argv[1]);
	 msgsnd(msqid, &sbuf, 80, IPC_NOWAIT);
sbuf.mtype = 2;
	strcpy(sbuf.mtext, argv[1]);
	 msgsnd(msqid, &sbuf, 80, IPC_NOWAIT);
}
sbuf.mtype = 0;
	msgsnd(msqid, &sbuf, 80, IPC_NOWAIT);
exit(0);
}


}
