/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:08:57 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/11 16:44:27 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_input(const char format, va_list args, t_flag fl)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_len((char)va_arg(args, int));
	else if (format == 's')
		count += ft_putstr_len((char *)va_arg(args, char *));
	else if (format == 'p')
		count += ft_printaddr((void *)va_arg(args, unsigned char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_len((int)va_arg(args, int), fl, format);
	else if (format == 'u')
		count += ft_putunbr_len((unsigned int)va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int),
			0, fl, format);
	else if (format == 'X')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int),
			1, fl, format);
	else if (format == '%')
		count += ft_putchar_len('%');
	return (count);
}

int	ft_flag_charset(const char c)
{
	if (c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

void	ft_init_flag(t_flag *flag)
{
	flag->hexa = 0;
	flag->sign = 0;
	flag->space = 0;
}

int	ft_put_flags(t_flag flag, const char format)
{
	int	count;

	count = 0;
	if (flag.hexa)
	{
		flag.sign = 0;
		flag.space = 0;
		if (format == 'x' || format == 'X')
			count += ft_putstr_len("0x");
	}
	if (flag.sign)
	{
		flag.space = 0;
		if (format == 'd' || format == 'i')
			count += ft_putstr_len("+");
	}
	if (flag.space)
	{
		if (format == 'd' || format == 'i')
			count += ft_putstr_len(" ");
	}
	return (count);
}

int	ft_get_flags(const char *format, size_t *i, va_list args)
{
	t_flag	flag;
	size_t	tmp;

	tmp = *i;
	ft_init_flag(&flag);
	while (ft_flag_charset(format[tmp]) && format[tmp])
	{
		if (format[tmp] == '#')
			flag.hexa = 1;
		else if (format[tmp] == ' ')
			flag.space = 1;
		else if (format[tmp] == '+')
			flag.sign = 1;
		tmp++;
	}
	*i = tmp;
	return (ft_parse_input(format[tmp], args, flag));
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_get_flags(&format[++i], &i, args);
		else
			count += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*	Flags
- #: Add '0x', for 'x | X'.
- 0: Add zero padded left, number is repetition - number size, if '-' : ignored, if '.' with numeric : ignored
- '-': Make value padded left, number is repetition - number size.
- ' ': Add ' ' before a positive number
- '+': Add '+' before a positive number, if ' ' : ignored.
- '.': 
*/
/*	Rules
- Flag repetition is ignored.
- No other flag accepted with 'x' or 'X
- 
*/