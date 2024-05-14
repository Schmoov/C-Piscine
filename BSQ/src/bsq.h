/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:18 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 17:57:54 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_sol_coords {
	int	boool;
	int	x;
	int	y;
	int	size;

}	t_sol_coords;

typedef struct s_parse{
	char	**grid;
	char	*map;
	int		x;
	int		y;
	char	*gui;
	int		boool;
	char	*first_line;
}	t_parse;


//Magic Trick
int				**init_int_mat(int x, int y);

void			fill_mat_with_zeros(int **mat, int x, int y);

int				**magic_trick(char **grid, int x, int y, char *gui);

//grille test
void			fill_grid_with_empty(char **grid, int x, char *gui);

void			print_grid(char **grid);

int				nb_obs_square(int **mat, int xi, int yi, int l);

int				ft_min(int x, int y);

t_sol_coords	is_there_empty_square(int **mat, int size, int x, int y);

t_sol_coords	solve(int **mat, int x, int y);

char			*parse_first_line(char *file_path);

void			reverse_str(char *str);

char			*get_pattern(char *first_line);

int				ft_strlen(char *str);

char			*convert_file(char *file_path);

int				ft_count_rows(char *map);

int				ft_control_rows(char *map);

char			**ft_split(char *str, char *charset);

int				ft_param_valid_map(char c, char empty, char obstacle);

int				ft_control_params_in_map(char *map, char empty, char obstacle);

int				check_everything(char *path);

char			**str_to_grid(char *file_path, t_parse *parsed);

int				get_line_number(char *str);

void			read_input(int fd);

char			*ft_strncat(char *dest, char *src, unsigned int nb);

int				ft_control_rows(char *map);

void			graphic_solve(int **mat, t_parse parse);

t_parse			parse_grid(char *filepath);

void			ft_print_tab(t_parse data);

t_sol_coords	trash_struct(void);

t_sol_coords	is_there_empty_square(int **mat, int size, int x, int y);

t_sol_coords	solve(int **mat, int x, int y);

char			**ft_crea_map(int nb_rows, int nb_cols);

void			ft_fill_map(t_parse *data, char *argv);

void			free_struct(t_parse data);

void			free_double_tab(char **tab);

#endif
