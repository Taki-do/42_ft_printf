/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:08:57 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/12 18:37:30 by taomalbe         ###   ########.fr       */
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
		count += ft_putstr_flag((char *)va_arg(args, char *), fl, format);
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
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0' || c == '.'
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	ft_init_flag(t_flag *flag)
{
	flag->hexa = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->align = 0;
	flag->minwid = 0;
	flag->number = 0;
	flag->zero = 0;
	flag->precise = 0;
}

int	ft_put_flags(t_flag flag, const char format, int count)
{
	int	cnt;

	cnt = 0;
	if (flag.hexa)
	{
		flag.sign = 0;
		flag.space = 0;
		if (format == 'x')
			cnt += ft_putstr_len("0x");
		if (format == 'X')
			cnt += ft_putstr_len("0X");
	}
	if (flag.sign)
	{
		flag.space = 0;
		if (format == 'd' || format == 'i')
			cnt += ft_putstr_len("+");
	}
	if (flag.space)
	{
		if (format == 'd' || format == 'i')
			cnt += ft_putstr_len(" ");
	}
	cnt += ft_put_combflags(flag, format, count);
	return (cnt);
}


int	ft_put_combflags(t_flag flag, const char format, int count)
{
	int	cnt;
	int	tmp;

	cnt = 0;
	if (flag.minwid)
	{
		tmp = count;
		while ((flag.minwid - tmp++) > 0)
				cnt += ft_putchar_len(' ');
	}
	else if (flag.align)
	{
		tmp = count;
		while ((flag.number - tmp++) > 0)
				cnt += ft_putchar_len(' ');
		flag.zero = 0;
	}
	if (flag.precise)
	{
		if (format == 'd' || format == 'i' || format == 'u' || format == 'x'
			|| format == 'X' || format == 's')
		{
			if (!flag.number)
				flag.zero = 0;
		}
	}
	if (flag.zero)
	{
		if (format == 'd' || format =='i' || format == 'u' || format == 'x'
			|| format == 'X')
		{
			tmp = count;
			while ((flag.number - tmp--) > 0)
				cnt += ft_putchar_len('0');
		}
	}
	return (cnt);
}

int	ft_is_flags(t_flag flag)
{
	if (!flag.align && !flag.hexa && !flag.minwid && !flag.number
		&& !flag.precise && !flag.sign && !flag.space && !flag.zero)
		return (0);
	return (1);
}

int	ft_is_var(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_get_flags(const char *format, size_t *i, va_list args)
{
	t_flag	flag;
	size_t	tmp;

	tmp = *i;
	ft_init_flag(&flag);
	while (ft_flag_charset(format[tmp]) && format[tmp])
	{
		if (format[tmp] == '-')
			flag.align = 1;
		if ((format[tmp] >= '1' && format[tmp] <= '9') && (!ft_is_flags(flag) || flag.align)
			&& !flag.minwid && !flag.precise)
			flag.minwid = ft_atoi_len(format + tmp, &tmp);
		if ((format[tmp] >= '1' && format[tmp] <= '9') && ft_is_flags(flag))
			flag.number = ft_atoi_len(format + tmp, &tmp);
		if (format[tmp] == '#')
			flag.hexa = 1;
		if (format[tmp] == ' ')
			flag.space = 1;
		if (format[tmp] == '+')
			flag.sign = 1;
		if (format[tmp] == '0')
			flag.zero = 1;
		if (format[tmp] == '.')
			flag.precise = 1;
		tmp++;
	}
	if (ft_is_flags(flag))
	{
		tmp--;
		while (!ft_is_var(format[tmp]) && format[tmp])
			tmp++;
	}
	*i = tmp;
	//printf("minwid : %d\n", flag.minwid);
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
	while (format[i] && i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_get_flags(format, &i, args);
		}
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