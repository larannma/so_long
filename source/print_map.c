#include "../include/so_long.h"

int	close_window(void)
{
	printf("Window closed\n");
	exit(1);
}

int	key_press(int keycode, t_m *m)
{
	if (keycode == 53)
	{
		mlx_destroy_window(m->mlx, m->mlx_win);
		exit(1);
	}
	if (keycode == 13 || keycode == 126)
		go_up(m);
	if (keycode == 1 || keycode == 125)
		go_down(m);
	if (keycode == 0 || keycode == 123)
		go_left(m);
	if (keycode == 2 || keycode == 124)
		go_right(m);
	return (0);
}

void	print_image(int a, t_m *m, int i, int j)
{
	if (a == 1)
		m->img = mlx_xpm_file_to_image(m->mlx, m->space, \
		&m->height, &m->width);
	else if (a == 2)
		m->img = mlx_xpm_file_to_image(m->mlx, m->wall, \
		&m->height, &m->width);
	else if (a == 3)
		m->img = mlx_xpm_file_to_image(m->mlx, m->player, \
		&m->height, &m->width);
	else if (a == 4)
		m->img = mlx_xpm_file_to_image(m->mlx, m->exit, \
		&m->height, &m->width);
	else
		m->img = mlx_xpm_file_to_image(m->mlx, m->collectible, \
		&m->height, &m->width);
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 70 * i, 70 * j);
}

void	proverka(t_m *m, int i, int j)
{
	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == '0')
				print_image(1, m, j, i);
			else if (m->map[i][j] == '1')
				print_image(2, m, j, i);
			else if (m->map[i][j] == 'P')
			{
				print_image(3, m, j, i);
				m->player_i = i;
				m->player_j = j;
			}
			else if (m->map[i][j] == 'E')
				print_image(4, m, j, i);
			else if (m->map[i][j] == 'C')
				print_image(5, m, j, i);
			j++;
		}
		i++;
	}
}

int	put_map(t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_2nd_struct(m);
	proverka(m, i, j);
	mlx_hook(m->mlx_win, 17, 1L << 0, close_window, m);
	mlx_hook(m->mlx_win, 2, 1L << 0, key_press, m);
	mlx_loop_hook(m->mlx, render_next_frame, m);
	return (0);
}
