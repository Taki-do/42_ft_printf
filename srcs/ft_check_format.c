/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:21 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/05 16:36:12 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_input(const char *format, va_list args, int *i)
{
	int		d;
	char	c;
	char	*s;

	if (ft_strstr(format, "%c"))
	{
		c = (char) va_arg(args, int);
		write(1, &c, 1);
		*i += 2;
	}
	else if (ft_strstr(format, "%s"))
	{
		s = (char *) va_arg(args, char *);
		ft_putstr(s);
		*i += 2;
	}
	else if (ft_strstr(format, "%d"))
	{
		d = (int) va_arg(args, int);
		ft_putnbr(d);
		*i += 2;
	}
	/*
	if (ft_strstr(format, "%p"))
	{
		
	}
	if (ft_strstr(format, "%i"))
	{
		
	}
	if (ft_strstr(format, "%u"))
	{
		
	}
	if (ft_strstr(format, "%x"))
	{
		
	}
	if (ft_strstr(format, "%X"))
	{
		
	}
	if (ft_strstr(format, "%%"))
	{
		
	}
	*/
	//new node, add char
	
}
