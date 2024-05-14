/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:42:19 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 23:09:28 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

int	buff_size(void);
int	is_num(char *str);
int	ft_strlen(char *str);
int	corectvalue(char *str);
int	cond(int ac, char **av);
int	is_triple_zero(char *str);
int	get_readable_arr_length(char *str);
int	get_sub_1000_readable_length(char *str);
int	ins_magnitude(char **res, char *str, int i_res, int i_str);
int	ins_composite_tens(char **res, char *str, int i_res, int i_str);
int	ins_single_word_tens(char **res, char *str, int i_res, int i_str);
int	ins_non_null_hundreds(char **res, char *str, int i_res, int i_str);
int	ins_readable_sub_1000(char **res, char *str, int i_res, int i_str);

void	ft_error(int x);
void	pre_zero(char *str);
void	burn_everything_and_run(char **res);
void	print_nb_split(char **nb_split, char *dict_as_str);

char	*atoword(char *str, char *to_find);
char	*ft_strcpy(char *dest, char *src);
char	**init_str_to_readable_arr(char	*str);
char	**str_to_readable_arr(char **res, char	*str, int i_str, int l_res);

#endif
