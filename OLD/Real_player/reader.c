#include "includes/filler.h"
#include "includes/list.h"
#include "includes/graph.h"
#include "limits.h"

int main()
{
	char *buff;
	int fd;
	int ret = 1;;

	fd = open("test.txt", O_RDONLY);
	buff = (char *)malloc(sizeof(char) * 300);
	ret = read(fd, buff, 600);
	buff[ret] = '\0';
	bfs(buff);
	return (0);
}
