int main() 
{
	char			*line;
	int				fd;

	// fd = open("file.txt", 0);
	line = get_next_line(1000);
	printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
}
