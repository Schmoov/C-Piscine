#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int	ft_hd_file(char *path);
int ft_hd_stdin();

//TO DO 
void	print_error(int error, char *path)
{
	write(2, "cat: ", 5);
	write(2, path, strlen(path));
	write(2, ": ", 2);
	write(2, strerror(error), strlen(strerror(error)));
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	error;
	int i = 1;

	if (argc == 1)
	{
		ft_hd_stdin();
	}
	while (i < argc)
	{
		error = ft_hd_file(argv[i]);
		if (error)
			print_error(error, argv[i]);
		i++;
	}
}
