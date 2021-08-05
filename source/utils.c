#include "../include/so_long.h"

void	init_sruct(t_check_map *check_map)
{
	check_map->player = 0;
	check_map->collectible = 0;
	check_map->exit = 0;
}

void	legal_symbols_check(t_m *m, int r, int c)
{
	if (!(m->map[r][c] == 'E' || m->map[r][c] == 'P' ||
		  m->map[r][c] == 'C' || m->map[r][c] == '1' ||
		  m->map[r][c] == '0'))
	{
		printf("Unknown symbols in the map\n");
		exit(1);
	}
}

void	init_2nd_struct(t_m *map)
{
	map->step = 0;
	map->player_i = 0;
	map->player_j = 0;
	map->flags = 0;
	map->height = 70;
	map->width = 70;
	map->wall = file_check("./final.XPM");
	map->space = file_check("./space.xpm");
	map->player = file_check("./turtle.XPM");
	map->collectible = file_check("./vod.XPM");
	map->exit = file_check("./exit_final.XPM");
}

char	*file_check(char *file)
{
	if (open(file, O_RDONLY) < 0)
		foo_error("File is mising\n");
	return (file);
}

int	render_next_frame(t_m *m)
{
	(void)m;
	return (0);
}
