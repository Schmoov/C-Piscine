/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print_memory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:04:38 by parden            #+#    #+#             */
/*   Updated: 2024/02/15 11:57:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

void	print_byte_in_hex(unsigned char byte)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &(base[(byte / 16)]), 1);
	write(1, &(base[(byte % 16)]), 1);
}

void	print_addr_in_hex(unsigned long intp)
{
	int				i;
	unsigned char	byte;

	i = 8;
	while (i > 0)
	{
		byte = (intp >> (8 * (i - 1)) % 256);
		print_byte_in_hex(byte);
		--i;
	}
}

unsigned int	print_content_in_hex(unsigned char *pc, unsigned int size_left)
{
	int				i;

	i = 0;
	while ((i < 16) && (size_left))
	{
		print_byte_in_hex(pc[i]);
		++i;
		--size_left;
		if (size_left)
		{
			print_byte_in_hex(pc[i]);
			--size_left;
		}
		else
			write(1, "  ", 2);
		++i;
		write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "     ", 5);
		i += 2;
	}
	return (size_left);
}

void	print_content_in_ascii(unsigned char *pc, unsigned int size_left)
{
	int	i;

	i = 0;
	while (i < 16 && size_left > (size_left - 1))
	{
		if ((pc[i] < ' ') || (pc[i] > '~'))
			write(1, ".", 1);
		else
			write(1, &pc[i], 1);
		++i;
		--size_left;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	intp;
	unsigned char	*addr_as_char;
	void			*og_addr;
	unsigned int	size_2;

	og_addr = addr;
	while (size)
	{
		intp = (unsigned long) addr;
		addr_as_char = (unsigned char *) addr;
		print_addr_in_hex(intp);
		write(1, ": ", 2);
		size_2 = size;
		size = print_content_in_hex(addr_as_char, size);
		print_content_in_ascii(addr_as_char, size_2);
		write(1, "\n", 1);
		addr_as_char += 16;
		addr = (void *)addr_as_char;
	}
	return (og_addr);
}
/*

int    main()
{
    char	*str_test = "Bonjour l\ns aminches\n\n\nc\'est fou.tout\0 tou
LINEBREAKt ce auon faire avec ce programme de mort aue jai passe deux jours
LINE complet a
LINEBREAK coder mdr jpp mais en vrai je suis heeeeeeeurux";
    void    *pv;
    pv = (void *) str_test;
    ft_print_memory(pv, 157);
    printf("Address of variable a = %p\n", pv);
    printf("Address of pointer ptr = %p\n", &pv);
}
*/
