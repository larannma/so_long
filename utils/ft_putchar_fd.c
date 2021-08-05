#include "../include/so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
