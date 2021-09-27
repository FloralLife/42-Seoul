#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

void gnl(int fd){
	char *nl = get_next_line(fd);
	printf("[%d] : %s\n", fd, nl);
	free(nl);
}

int main(){
	// int fd = open("asdf", O_RDONLY);
	// while(1){
	// 	char *nl = get_next_line(fd);
	// 	if (nl == NULL) break;
	// 	printf("%s", nl);
	// 	free(nl);
	// }
	int fd[4];
	fd[0] = open("gnlTester/files/41_with_nl", O_RDWR);
	get_next_line(1000);
	get_next_line(fd[0]);

	open("gnlTester/files/42_with_nl", O_RDWR);
	get_next_line(1001);
	get_next_line(fd[1]);

	open("gnlTester/files/43_with_nl", O_RDWR);
	get_next_line(1002);
	get_next_line(fd[2]);

	get_next_line(1003);
	get_next_line(fd[0]);

	get_next_line(1004);
	get_next_line(fd[1]);

	get_next_line(1005);
	get_next_line(fd[2]);

	fd[3] = open("gnlTester/files/nl", O_RDWR);
	get_next_line(1006);
	get_next_line(fd[3]);
	get_next_line(1007);
	get_next_line(fd[3]);
	while(1);
}
