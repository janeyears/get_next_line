#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int	main(int ac, char **av)
{
	char	*line;
	int	fd;
	int	i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line %d for fd %d: %s", i, fd, line);;
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
/*
int	main(int ac, char **av)
{
	char	*line;
	int	fd1;
	int	fd2;
	int	i;
	int	a;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	if (!fd1)
		return (1);
	i = 1;
	line = get_next_line(fd1);
	printf("Line %d for fd %d: %s", i, fd1, line);;
	free(line);
	i++;
	fd2 = open(av[2], O_RDONLY);
	if (!fd2)
		return (1);
	a = 1;
	line = get_next_line(fd2);
	printf("Line %d for fd %d: %s", a, fd2, line);;
	free(line);
	a++;
	line = get_next_line(fd1);

	printf("Line %d for fd %d: %s", i, fd1, line);;
	free(line);
	i++;
	line = get_next_line(fd2);
	printf("Line %d for fd %d: %s", a, fd2, line);;
	free(line);
	a++;
	close(fd1);
	close(fd2);
	return (0);
}
*/
