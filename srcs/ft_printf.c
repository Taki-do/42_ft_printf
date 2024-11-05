/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:28 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/05 16:36:49 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;

	i = 0;
	va_list args;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_parse_input(format, args, &i);
		}
		else
		{
			write(1, format + i, 1);
			i++;
		}
	}
	va_end(args);
	return (0);
}
