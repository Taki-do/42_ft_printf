/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:03:57 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/08 18:10:20 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	count;

	ft_printf("My printf :\n");
	count = ft_printf("%3.10s", "bombastic");
	printf("\ncount = %d\n", count);

	printf("Re printf :\n");
	count = printf("%3.10s", "bombastic");
	printf("\ncount = %d\n", count);
}
