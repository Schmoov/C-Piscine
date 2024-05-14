#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 30720


int	ft_display_file(const char *path)
{
	int				fd;
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;

	bytes_read = BUF_SIZE;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (bytes_read == BUF_SIZE)
	{
		bytes_read = read(fd, (void *)buf, BUF_SIZE);
		if (bytes_read == -1)
			return (errno);
		write(1, buf, bytes_read);
	}
	close(fd);
	return (0);
}

int	ft_display_stdin(void)
{
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(0, (void *)buf, BUF_SIZE);
		if (bytes_read == -1)
			return (errno);
		write(1, buf, bytes_read);
	}
	return (0);
}

