/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:21 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/06 16:05:49 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_input(const char format, va_list args)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		ft_putstr((char *)va_arg(args, char *));
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
