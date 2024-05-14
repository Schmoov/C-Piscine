#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int file_length(char *path, int *ret_len);
int ft_skip(int fd, int toskip);
int	ft_display_fd(int fd);
int ft_tail_stdin(int n);

void	print_error(int error, char *path)
{
	write(2, "tail: cannot open \'", 20);
	write(2, path, strlen(path));
	write(2, "\' for reading: ", 16);
	write(2, strerror(error), strlen(strerror(error)));
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	error;
	int i = 3;
	int fd;
	int file_l;
	int n = atoi(argv[2]);

	if (argc == 3)
	{
		ft_tail_stdin(atoi(argv[2]));
	}
	while (i < argc)
	{
		error = file_length(argv[i], &file_l);
		if (error)
			print_error(error, argv[i]);
		else
		{
			fd = open(argv[i], O_RDONLY);
			if (n < file_l)
				ft_skip(fd,file_l - n);
			if (argc !=4)
			{
				write(1,"==> ",4);
				write(1, argv[i], strlen(argv[i]));
				write(1," <==\n",5);
			}
			ft_display_fd(fd);
			close(fd);
			if ((argc != 4)&&(i!=argc-1))
				write(1,"\n",1);
		}
		i++;
	}
}
