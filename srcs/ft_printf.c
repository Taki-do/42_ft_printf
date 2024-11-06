/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:28 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/06 15:37:52 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_is_strstr(format + i, "%%"))
		{
			ft_putchar('%');
			i++;
		}
		else if (format[i] == '%')
			ft_parse_input(format[++i], args);
		else
			write(1, format + i, 1);
		i++;
	}
	va_end(args);
	return (0);
}
