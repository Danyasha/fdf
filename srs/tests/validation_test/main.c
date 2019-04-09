#include "../tests.h"

static	int		exiter(char *s)
{
	ft_putstr(s);
	return (0);
}

static	void	display_map(t_map *map)
{
	t_point	**p;
	p = map->points;
	int i = 0;
	int	j = 0;
	int maxh = map->size_h;
	while (p[i])
	{
		j = 0;
		while (j < maxh)
		{
			printf("%i ", p[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int argn, char **argv)
{
	int		fd;
	t_map	*map;

	fd = open(argv[1], O_RDONLY);
	if (argn != 2)
		return(exiter("usage: ./fdf filename\n"));
	if (read(fd, NULL, 0) < 0)
		return(exiter("invalid file\n"));
	if(!(map = validate_main(fd)))
		return(exiter("bad map\n"));
	else
	{
		display_map(map);
		ft_putstr("norme\n");
	}
	close (fd);
	return (0);
}