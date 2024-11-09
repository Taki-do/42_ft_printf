/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:28 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/09 14:48:06 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_input(const char format, va_list args, t_flag flags)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_len((char)va_arg(args, int));
	else if (format == 's')
		count += ft_putstr_len((char *)va_arg(args, char *), flags);
	else if (format == 'p')
		count += ft_printaddr((void *)va_arg(args, unsigned char *), flags);
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_len((int)va_arg(args, int), flags);
	else if (format == 'u')
		count += ft_putunbr_len((unsigned int)va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int), 0,
			flags.prefix, flags);
	else if (format == 'X')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int), 1,
			flags.prefix, flags);
	else if (format == '%')
		count += ft_putchar_len('%');
	if (format == 'd' || format == 'i')
		count += ft_align(flags.size, count);
	return (count);
}

int	ft_charset(const char c)
{
	if (c == '-' || c == '.' || c == '#'
		|| c == ' ' || c == '+' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	ft_init_t_flag(t_flag *flags)
{
	flags->align = 0;
	flags->precise = 0;
	flags->prefix = 0;
	flags->sign = 0;
	flags->spaces = 0;
	flags->zeros = 0;
	flags->size = 0;
	flags->size2 = 0;
}

int	ft_flags_input(const char *format, va_list args, int *cursor)
{
	size_t	i;
	t_flag	flags;

	i = 0;
	ft_init_t_flag(&flags);
	while (format[i] && ft_charset(format[i]))
	{
		if (format[i] == '-')
			flags.align = 1;
		else if (format[i] == '0')
			flags.zeros = 1;
		else if (format[i] == '.')
			flags.precise = 1;
		else if (format[i] == '#')
			flags.prefix = 1;
		else if (format[i] == ' ')
			flags.spaces = 1;
		else if (format[i] == '+')
			flags.sign = 1;
		else if (format[i] >= '1' && format[i] <= '9')
		{
			if (!flags.precise)
				flags.size = ft_atoi(&format[i]);
			else
				flags.size2 = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
		}
		i++;
	}
	*cursor += i;
	return (ft_priority(flags, format[i], args));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_flags_input(&format[++i], args, &i);
		else
			count += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
