#ifndef SO_LONG_H
# define    SO_LONG_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include   <stdio.h>
# include	<mlx.h>

# define BUFFER_SIZE 98

typedef struct s_m
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		count;
	int		width;
	int		height;
	void	*wall;
	void	*space;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*img;
	int		player_i;
	int		player_j;
	int		coll;
	int		flags;
	int		step;
}	t_m;

typedef struct s_check_map
{
	int	player;
	int	collectible;
	int	exit;
}				t_check_map;

void	check_map(t_m *m, int count);
int		put_map(t_m *m);
void	print_image(int a, t_m *m, int i, int j);
void	go_up(t_m *m);
void	go_down(t_m *m);
void	go_left(t_m *m);
void	go_right(t_m *m);
void	init_2nd_struct(t_m *map);
void	foo_error(char *message);
void	init_sruct(t_check_map *check_map);
void	legal_symbols_check(t_m *m, int r, int c);
void	init_2nd_struct(t_m *map);
char	*file_check(char *file);
int		render_next_frame(t_m *m);

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);

#endif
