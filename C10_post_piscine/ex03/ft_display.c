#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 16

void	ft_print_memory(void *addr, unsigned int bytes_read, unsigned int tot_bytes);
void	print_addr_in_hex(unsigned long intp);

int	ft_hd_file(const char *path)
{
	int				fd;
	unsigned char	buf[BUF_SIZE];
	int				bytes_read;
	int				tot_bytes = 0;

	bytes_read = BUF_SIZE;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (bytes_read == BUF_SIZE)
	{
		bytes_read = read(fd, (void *)buf, BUF_SIZE);
		if (bytes_read == -1)
			return (errno);
		tot_bytes += bytes_read;
		ft_print_memory(buf, bytes_read, tot_bytes-bytes_read);
	}
	if (tot_bytes%16)
	{
		print_addr_in_hex(tot_bytes);
		write(1, "\n",1);
	}
	close(fd);
	return (0);
}

int	ft_hd_stdin(void)
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

