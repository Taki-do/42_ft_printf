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

void	ft_sputstr(char *str)
{
	if (str == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(str);
}

void	ft_parse_input(const char format, va_list args)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		ft_sputstr((char *)va_arg(args, char *));
	else if (format == 'p')
		ft_printaddr((void *)va_arg(args, unsigned char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr((int)va_arg(args, int));
	else if (format == 'u')
		ft_putunbr((unsigned int)va_arg(args, unsigned int));
	else if (format == 'x')
		ft_lowhexa((unsigned int)va_arg(args, unsigned int));
	else if (format == 'X')
		ft_upphexa((unsigned int)va_arg(args, unsigned int));
}
//If '%', while there valid flags, check if this can means someting ? And after all dispatch

//- Is '0', check if there is a number after, do number - sizeof(%d) to know how may '0' needed
//to be print starting from left. 'd | i | u | x | X'.

//- '-', get the content to the left, add spaces if a number is specified after '"%-5%d", 42'
//will be : "42   ". 'all'.

//- '.', precision, it define minimal number of caracters to print, like for '"%.3d", 7' =
//'007', or for '"%.3s", "hello"' = 'hel'. 'd | i | u | x | X'.

//- '#', for the hexadecimal content, display '0x' in front. 'x | X'.

//- '+', force to print the sign, '+' or '-'. 'd | i'.

//- ' ', put a space before the integers, but if there is a sign it takes priority. 'd | i'.

//- Flag priority, '- > 0', '+- > ' '', '.0 > 05', 