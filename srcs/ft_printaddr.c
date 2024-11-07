/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:39 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/07 12:08:17 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_inhex(unsigned char print)
{
	size_t	i;
	char	stock[10];
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (print)
	{
		stock[i] = hex[print % 16];
		print /= 16;
		i++;
	}
	ft_putstr(ft_strrev(stock));
}

void	ft_printaddr(void *addr)
{
	int				i;
	unsigned char	*print;

	i = 7;
	print = (unsigned char *)&addr;
	ft_putstr("0x");
	while (i >= 0)
	{
		ft_inhex(print[i]);
		i--;
	}
}
