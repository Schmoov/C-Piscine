#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1048576

int	ft_display_file(const char *path)
{
	int				fd;
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;

	bytes_read = BUF_SIZE;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (bytes_read == BUF_SIZE)
	{
		bytes_read = read(fd, (void *)buf, BUF_SIZE);
		if (bytes_read == -1)
			return (-1);
		write(1, buf, bytes_read);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	all_good;

	if (argc == 1)
		write(1, "File name missing.", 18);
	else if (argc > 2)
		write(1, "Too many arguments.", 19);
	else
	{
		all_good = ft_display_file(argv[1]);
		if (all_good == -1)
			write(1, "Cannot read file.", 18);
	}
}
