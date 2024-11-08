/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:21 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:27 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr_len(unsigned int nb)
{
	int	count;

	count = 0;
	ft_putunbr(nb);
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_hexa_len(unsigned int dec, int ul)
{
	size_t	i;
	char	*hexa;
	char	stock[100];

	i = 0;
	if (ul == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	while (dec)
	{
		stock[i] = hexa[dec % 16];
		dec /= 16;
		i++;
	}
	stock[i] = '\0';
	return (ft_putstr_len(ft_strrev(stock)));
}
//If '%', while there valid flags, check if this can means someting ?
// And after all dispatch

//- Is '0', check if there is a number after, do number - sizeof(%d)
// to know how may '0' needed
//to be print starting from left. 'd | i | u | x | X'.

//- '-', get the content to the left, add spaces if a number is
// specified after '"%-5%d", 42'
//will be : "42   ". 'all'.

//- '.', precision, it define minimal number of caracters to print
//, like for '"%.3d", 7' =
//'007', or for '"%.3s", "hello"' = 'hel'. 'd | i | u | x | X'.

//- '#', for the hexadecimal content, display '0x' in front. 'x | X'.

//- '+', force to print the sign, '+' or '-'. 'd | i'.

//- ' ', put a space before the integers, but if there is a sign it
// takes priority. 'd | i'.

//- Flag priority, '- > 0', '+- > ' '', '.0 > 05', 