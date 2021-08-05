#include "../include/so_long.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*m;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	m = (char *)malloc(sizeof(char) * i + 1);
	if (m == NULL)
		return (NULL);
	ft_memmove(m, s1, ft_strlen(s1));
	ft_memmove(m + ft_strlen(s1), s2, ft_strlen(s2));
	m[i] = '\0';
	free(s1);
	return (m);
}

static int	check_remain(char **remain, char **line)
{
	char	*pointer;
	char	*remain_two;

	remain_two = *remain;
	pointer = ft_strchr(*remain, '\n');
	if (pointer)
	{
		*pointer = '\0';
		*line = ft_strdup(*remain);
		if (!line)
		{
			free(line);
			return (-1);
		}
		*remain = ft_strdup(pointer + 1);
		if (!*remain)
			return (-1);
		free(remain_two);
		return (1);
	}
	return (0);
}

static	int	ft_free(char *line, int i)
{
	free (line);
	return (i);
}

static	int	next_wave(int fd, char **remain, char **line)
{
	char		*buf;
	int			i;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		*remain = ft_strjoin(*remain, buf);
		if (*remain == NULL)
			return (ft_free(buf, -1));
		if (check_remain(remain, line) == 1)
			return (ft_free(buf, 1));
		else if (check_remain(remain, line) == -1)
			return (ft_free(buf, -1));
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (check_remain(remain, line) == 1)
		return (ft_free(buf, 1));
	*line = ft_strdup(*remain);
	free(*remain);
	*remain = NULL;
	return (ft_free(buf, 0));
}

int	get_next_line(int fd, char **line)
{
	static char	*remain;
	int			i;

	if (fd < 0 || (read(fd, 0, 0) < 0) || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	if (!remain)
	{
		remain = ft_strdup("");
		if (!remain)
			return (-1);
	}
	i = next_wave(fd, &remain, line);
	return (i);
}
