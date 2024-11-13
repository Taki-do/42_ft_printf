/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:39 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/12 18:37:15 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_len(int nb, t_flag fl, const char format)
{
	int	tmp;
	int	sign;
	int	count;

	count = 0;
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	if (nb == 0)
		return (1);
	tmp = nb;
	while (tmp)
	{
		count++;
		tmp /= 10;
	}
	//printf("here : %d\n", fl.number);
	if (fl.align)
	{
		if (sign)
			count += ft_putchar_len('-');
		ft_putnbr(nb);
		count += ft_put_flags(fl, format, count);
	}
	if (!fl.align)
	{
		count += ft_put_flags(fl, format, count + 1);
		if (sign)
			count += ft_putchar_len('-');
		ft_putnbr(nb);
	}
	return (count);
}

int	ft_putchar_len(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_flag(const char *str, t_flag flag, const char format)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!str)
	{
		if (flag.precise && !flag.align)
		{
			if (flag.number >= 6)
			{
				cnt += ft_put_flags(flag, format, 6);
				cnt += ft_putstr_len(str);
			}
			else if (flag.minwid >= 6)
				cnt += ft_put_flags(flag, format, 0);
			else
			{
				cnt += ft_put_flags(flag, format, 0);
				cnt += ft_putstr_len("");
			}
		}
		else if (flag.align)
		{
			if (flag.minwid && !flag.number && flag.precise && !flag.align)
				flag.number = flag.minwid;
			if (flag.minwid >= 6)
			{
				if (flag.precise)
				{
					if (flag.number >= 6)
					{
						cnt += ft_putstr_len(str);
						cnt += ft_put_flags(flag, format, 6);
					}
					else
					{
						cnt += ft_put_flags(flag, format, 0);
						cnt += ft_putstr_len("");
					}
				}
				else
				{
					cnt += ft_putstr_len(str);
					cnt += ft_put_flags(flag, format, 6);
				}
			}
			else if (flag.number >= 6)
			{
				cnt += ft_put_flags(flag, format, 6);
				cnt += ft_putstr_len(str);
			}
			else if ((flag.align || !ft_is_flags(flag)) && !flag.minwid)
			{
				if (flag.precise)
				{
					cnt += ft_put_flags(flag, format, 0);
					cnt += ft_putstr_len("");
				}
				else
				{
					cnt += ft_putstr_len(str);
					cnt += ft_put_flags(flag, format, 6);
				}
			}
			else if ((flag.align || !ft_is_flags(flag)) && flag.minwid)
			{
				if (flag.precise)
				{
					cnt += ft_put_flags(flag, format, 0);
					cnt += ft_putstr_len("");
				}
				else
				{
					cnt += ft_putstr_len(str);
					cnt += ft_put_flags(flag, format, 6);
				}
			}
			else
			{
				cnt += ft_put_flags(flag, format, 0);
				cnt += ft_putstr_len("");
			}
		}
		else
		{
			cnt += ft_put_flags(flag, format, 6);
			cnt += ft_putstr_len(str);
		}
		return(cnt);
	}
	else if (flag.minwid && flag.align && !flag.number)
	{
		if (flag.precise)
			return (ft_put_flags(flag, format, 0));
		return (ft_putstr_len(str) + ft_put_flags(flag, format, ft_strlen(str)));
	}
	else if (!flag.precise)
		cnt = ft_put_flags(flag, format, ft_strlen(str));
	else if (!flag.number)
		cnt = ft_put_flags(flag, format, 0);
	else if (flag.number && flag.precise)
	{
		if ((size_t)flag.number > ft_strlen(str))
			flag.number = ft_strlen(str);
		if (!flag.align)
			cnt = ft_put_flags(flag, format, flag.number);
		while (str[i] && i < flag.number)
			ft_putchar(str[i++]);
		if (flag.align)
			cnt = ft_put_flags(flag, format, flag.number);
	}
	while (str[i] && !flag.precise)
		ft_putchar(str[i++]);
	return (cnt + i);
}

int	ft_putstr_len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_printhex(unsigned long print)
{
	size_t	i;
	char	stock[20];
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (print == 0)
		return (ft_putchar_len('0'));
	while (print)
	{
		stock[i] = hex[print % 16];
		print /= 16;
		i++;
	}
	stock[i] = '\0';
	return (ft_putstr_len(ft_strrev(stock)));
}

int	ft_printaddr(void *addr)
{
	int				count;
	unsigned long	print;

	count = 0;
	print = (unsigned long)addr;
	if (print == 0)
		return (count + ft_putstr_len("(nil)"));
	count = ft_putstr_len("0x");
	return (count + ft_printhex(print));
}
