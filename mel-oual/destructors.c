*void del_map(t_map **map)
{
	free(*map);
	map = NULL;
	return(NULL);
}
