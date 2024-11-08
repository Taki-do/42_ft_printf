/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:39 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/08 18:07:06 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_len(int nb, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.sign == 1 && nb >= 0)
		count += ft_putchar_len('+');
	else if (flags.spaces == 1 || flags.precise == 1)
		count += ft_align(flags.size, ft_nbr_size(nb));
	else if (flags.zeros == 1)
		count += ft_zeros(flags.size, ft_nbr_size(nb));
	ft_putnbr(nb);
	if (nb == 0)
		return (1 + count);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_putchar_len(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(const char *str, t_flag flags)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	if (!str)
	{
		if (flags.precise)
			return (0);
		return (ft_putstr_len("(null)", flags));
	}
	if (!flags.precise)
		cnt += ft_align(flags.size, ft_strlen(str));
	while (str[i] && i < flags.size)
		ft_putchar(str[i++]);
	return (i + cnt);
}

int	ft_printhex(unsigned long print, t_flag flags)
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
	return (ft_putstr_len(ft_strrev(stock), flags));
}

int	ft_printaddr(void *addr, t_flag flags)
{
	int				count;
	unsigned long	print;

	count = 0;
	print = (unsigned long)addr;
	if (print == 0)
		return (count + ft_putstr_len("(nil)", flags));
	count = ft_putstr_len("0x", flags);
	return (count + ft_printhex(print, flags));
}
