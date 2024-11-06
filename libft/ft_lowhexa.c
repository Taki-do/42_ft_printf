/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:17:44 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/06 14:51:44 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lowhexa(unsigned int dec)
{
	size_t	i;
	char	*hexa;
	char	stock[100];

	i = 0;
	hexa = "0123456789abcdef";
	while (dec)
	{
		stock[i] = hexa[dec % 16];
		dec /= 16;
		i++;
	}
	stock[i] = '\0';
	ft_putstr(ft_strrev(stock));
}
