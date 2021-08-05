#include "../include/so_long.h"

void	go_up(t_m *m)
{
	if (m->map[m->player_i - 1][m->player_j] == 'C')
	{
		m->coll--;
		print_image(3, m, m->player_j, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->map[m->player_i - 1][m->player_j] = '0';
		m->step++;
		printf("steps: %d\n", m->step);
	}
	if (m->map[m->player_i - 1][m->player_j] != '1' && \
		m->map[m->player_i - 1][m->player_j] != 'E' )
	{
		print_image(3, m, m->player_j, m->player_i - 1);
		print_image(1, m, m->player_j, m->player_i);
		m->step++;
		printf("steps: %d\n", m->step);
	}
	m->player_i = m->player_i - 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll > 0)
		m->player_i = m->player_i + 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll == 0)
		exit(1);
	if (m->map[m->player_i][m->player_j] == '1')
		m->player_i = m->player_i + 1;
}

void	go_down(t_m *m)
{
	if (m->map[m->player_i + 1][m->player_j] == 'C')
	{
		m->coll--;
		print_image(3, m, m->player_j, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->map[m->player_i + 1][m->player_j] = '0';
		m->step++;
		printf("steps: %d\n", m->step);
	}
	if (m->map[m->player_i + 1][m->player_j] != '1' && \
		m->map[m->player_i + 1][m->player_j] != 'E' )
	{
		print_image(3, m, m->player_j, m->player_i + 1);
		print_image(1, m, m->player_j, m->player_i);
		m->step++;
		printf("steps: %d\n", m->step);
	}
	m->player_i = m->player_i + 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll > 0)
		m->player_i = m->player_i - 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll == 0)
		exit(1);
	if (m->map[m->player_i][m->player_j] == '1')
		m->player_i = m->player_i - 1;
}

void	go_left(t_m *m)
{
	if (m->map[m->player_i][m->player_j - 1] == 'C')
	{
		m->coll--;
		print_image(3, m, m->player_j, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->map[m->player_i][m->player_j - 1] = '0';
		m->step++;
		printf("steps: %d\n", m->step);
	}
	if (m->map[m->player_i][m->player_j - 1] != '1' && \
		m->map[m->player_i][m->player_j - 1] != 'E' )
	{
		print_image(3, m, m->player_j - 1, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->step++;
		printf("steps: %d\n", m->step);
	}
	m->player_j = m->player_j - 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll > 0)
		m->player_j = m->player_j + 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll == 0)
		exit(1);
	if (m->map[m->player_i][m->player_j] == '1')
		m->player_j = m->player_j + 1;
}

void	go_right(t_m *m)
{
	if (m->map[m->player_i][m->player_j + 1] == 'C')
	{
		m->coll--;
		print_image(3, m, m->player_j, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->map[m->player_i][m->player_j + 1] = '0';
		m->step++;
		printf("steps: %d\n", m->step);
	}
	if (m->map[m->player_i][m->player_j + 1] != '1' && \
		m->map[m->player_i][m->player_j + 1] != 'E' )
	{
		print_image(3, m, m->player_j + 1, m->player_i);
		print_image(1, m, m->player_j, m->player_i);
		m->step++;
		printf("steps: %d\n", m->step);
	}
	m->player_j = m->player_j + 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll > 0)
		m->player_j = m->player_j - 1;
	if (m->map[m->player_i][m->player_j] == 'E' && m->coll == 0)
		exit(1);
	if (m->map[m->player_i][m->player_j] == '1')
		m->player_j = m->player_j - 1;
}
