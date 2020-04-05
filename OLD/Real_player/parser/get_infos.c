#include "../includes/filler.h"

void get_infos(t_infos *infos)
{
	int fd;
	char *buffer;
	int ret;
	char *tmp;

	fd = open(0,  O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * 315);
	if (read(fd, buffer, 315) > 0)
	{
		if(ft_locat_str(buffer, "p1 : [players/mel-oual.filler]"))
			infos->p = 1;
		else
			infos->p = 2;
		tmp = ft_locat_str(buffer, "Plateau");
		infos->weight = ft_atoi(tmp + 8);
		infos->hight = ft_atoi(tmp + 11);
	}
	free(buffer);


}
