

#include <dirent.h>

#include<string.h>

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER 2000

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
char buf[BUFFER];
	int t, f1, f2, n;
fprintf(stderr,"1");
    dir = opendir(argv[1]);
    if (!dir) {
        perror(argv[1]);
        
    };

    while ( (entry = readdir(dir)) != NULL) {
		char **argm = argv;
//fprintf(stderr,"2");
//		argm[1]=argv[1];
//argm[2]=argv[2];
//fprintf(stderr,"9");

		strcat(argm[1], entry->d_name);
		strcat(argm[2], entry->d_name);
perror(argv[2]);

	if ((f1 = open(argm[1], O_RDONLY)) == -1)
		fprintf(stderr,"1");
	if ((f2= open(argm[2], O_WRONLY |O_CREAT, S_IRUSR | S_IWUSR )) == -1)
fprintf(stderr,"1");
//fprintf(stderr, "4");
while ((n = read(f1, buf, BUFFER)) > 0)
if (write(f2, buf, n) != n)
fprintf(stderr, "3");
close (f1);
close(f2);
        printf(" %s [%d]  \n",  entry->d_name, entry->d_type);
    };
fprintf(stderr,"5");
    closedir(dir);
};
