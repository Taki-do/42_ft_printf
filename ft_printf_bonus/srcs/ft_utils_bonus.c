/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:36:33 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/08 19:01:14 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_priority(t_flag flags, const char format, va_list args)
{
	if ((flags.align == 1 || flags.precise == 1) && flags.zeros == 1)
		flags.zeros = 0;
	if (flags.sign == 1 && flags.spaces == 1)
		flags.spaces = 0;
	return (ft_parse_input(format, args, flags));
}

int	ft_align(int size, int cnt)
{
	int	count;

	count = 0;
	while (size - cnt > 0)
	{
		ft_putchar(' ');
		size--;
		count++;
	}
	return (count);
}

int	ft_zeros(int size, int cnt)
{
	int	count;

	count = 0;
	while (size - cnt > 0)
	{
		ft_putchar('0');
		size--;
		count++;
	}
	return (count);
}

int	ft_nbr_size(int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

