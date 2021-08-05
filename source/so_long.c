#include "../include/so_long.h"

void	extention_check(char **argv)
{
	int		found;
	char	*p;

	found = 0;
	p = ft_strrchr(argv[1], '.');
	if (p)
	{
		found = ft_strcmp(p, ".ber");
		if (found != 0)
			foo_error("Wrong file extention\n");
	}
}

void	empty_check(char **argv, char *line, t_m *m)
{
	int	fd;
	int	check;

	check = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read(fd, 0, 0) < 0))
		foo_error("Couldn't read from the file\n");
	while (get_next_line(fd, &line))
	{
		m->width = (int)ft_strlen(line);
		m->count++;
		free(line);
		check++;
	}
	free(line);
	close(fd);
	if (check == 0)
		foo_error("File is empty\n");
}

void	read_file(t_m *m, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	extention_check(argv);
	empty_check(argv, line, m);
	m->map = ft_calloc(m->count + 1, sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (m->width != (int)ft_strlen(line))
			foo_error("Your map is not a ractangle\n");
		m->map[i++] = ft_strdup(line);
		free(line);
	}
	free(line);
	close(fd);
}

void	init(t_m *s)
{
	s->count = 0;
	s->width = 0;
	s->height = 0;
}

int	main(int argc, char **argv)
{
	t_m	m;

	init(&m);
	if (argc != 2)
		foo_error("Wrong number of arguments\n");
	read_file(&m, argv);
	check_map(&m, m.count);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, (m.width + 1) * 70, \
		 m.count * 70, "so_long");
	put_map(&m);
	mlx_loop(m.mlx);
}
