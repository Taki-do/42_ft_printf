/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:31:57 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/06 16:02:45 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	d;
	char c;
	char *s;

	d = 021;
	c = 98;
	s = "test";
	ft_printf("rien %p, %s, %Xouii\n", (void *)s, s, -424);
	   printf("rien %p, %s, %Xouii\n", (void *)s, s, -424);
}