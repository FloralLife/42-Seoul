#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(){
	int fd = open("asdf", O_RDONLY);
	char *gnl;
	while(1){
		gnl = get_next_line(fd);
		if (gnl == NULL) break;
		printf("%s\n", gnl);
	}
	free(gnl);
	while(1);
}
