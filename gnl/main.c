#include "get_next_line_bonus.h"
#include <fcntl.h>

void gnl(int fd){
	char *nl = get_next_line(fd);
	printf("%s\n", nl);
	free(nl);
}

int main(){
	int fd1 = open("1", O_RDONLY);
	int fd2 = open("2", O_RDONLY);
	int fd3 = open("3", O_RDONLY);
	gnl(fd1);
	gnl(fd2);
	gnl(fd3);
	gnl(fd1);
	gnl(fd2);
	gnl(fd3);
	gnl(fd2);
	gnl(fd3);
	gnl(fd3);
	gnl(fd1);
	gnl(fd1);
	gnl(9);
	gnl(fd3);
	gnl(fd1);
	gnl(fd2);
	gnl(fd3);
	close(3);
	gnl(3);
	while(1);
}
