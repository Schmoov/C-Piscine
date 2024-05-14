#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 30720

int file_length(char *path, int *ret_len)
{
	int bytes = BUF_SIZE;
	int length = 0;
	unsigned char buf[BUF_SIZE];
	int fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (bytes==BUF_SIZE)
	{
		bytes = read(fd,(void *)buf,BUF_SIZE);
		if (bytes == -1)
			return (errno);
		length +=bytes;
	}
	close(fd);
	*ret_len = length;
	return (0);
}

int ft_skip(int fd, int toskip)
{
	unsigned char buf[BUF_SIZE];
	int bytes;

	while (toskip >= BUF_SIZE)
	{
		bytes = read(fd, buf, BUF_SIZE);
		if (bytes == -1)
			return (errno);
		toskip -= BUF_SIZE;
	}
	if (toskip)
	{
		bytes = read(fd, buf, toskip);
		if (bytes == -1)
			return (errno);
	}
	return (0);
}

int	ft_display_fd(int fd)
{
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;

	bytes_read = BUF_SIZE;
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

int	ft_tail_stdin(int n)
{
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;

	bytes_read = read(0, (void *)buf, BUF_SIZE);
	if (bytes_read == -1)
		return (errno);
	if (n>=bytes_read)
		write(1, buf, bytes_read);
	else
		write(1,&buf[bytes_read-n],n);
	return (0);
}

