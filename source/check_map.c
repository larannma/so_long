#include "../include/so_long.h"

void	check_utils_two(t_m *m, t_check_map *check_map)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (m->map[r])
	{
		while (m->map[r][c])
		{
			legal_symbols_check(m, r, c);
			if (m->map[r][c] == 'E')
				check_map->exit++;
			if (m->map[r][c] == 'P')
				check_map->player++;
			if (m->map[r][c] == 'C')
			{
				check_map->collectible++;
				m->coll += 1;
			}
			c++;
		}
		c = 0;
		r++;
	}
}

void	check_utils(t_m *m, int count)
{
	t_check_map	check_map;

	(void)count;
	init_sruct(&check_map);
	check_utils_two(m, &check_map);
	if (check_map.exit != 1 || check_map.player != 1 || \
		check_map.collectible == 0)
	{
		printf("Wrong number of exits/players/collectibles\n");
		exit(1);
	}
}

void	check_north_south(t_m *m, int count)
{
	int	c;

	c = 0;
	while (m->map[count][c])
	{
		if (m->map[count][c] != '1')
		{
			printf("Map is wrong!\n");
			exit(1);
		}
		c++;
	}
	m->width = c - 1;
}

void	check_west_east(t_m *m, int count)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while (r <= count)
	{
		if (m->map[r][c] != '1')
			exit(1);
		if (m->map[r][(ft_strlen(m->map[r]) - 1)] != '1')
			exit(1);
		r++;
	}
}

void	check_map(t_m *m, int count)
{
	check_north_south(m, 0);
	check_north_south(m, count - 1);
	check_west_east(m, count - 1);
	check_utils(m, count);
}
