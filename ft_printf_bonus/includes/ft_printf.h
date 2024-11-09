/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:18:22 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/09 14:28:14 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h> //Warning

typedef struct s_flag
{
	int	zeros;
	int	align;
	int	sign;
	int	spaces;
	int	prefix;
	int	precise;
	int	size;
	int	size2;
}	t_flag;

int		ft_printf(const char *format, ...);
int		ft_printaddr(void *addr, t_flag flags);
int		ft_putnbr_len(int nb, t_flag flags);
int		ft_putunbr_len(unsigned int nb);
int		ft_putchar_len(const char c);
int		ft_putstr_len(const char *str, t_flag flags);
int		ft_hexa_len(unsigned int dec, int ul, int prefix, t_flag flags);

// Bonus

int		ft_priority(t_flag flags, const char format, va_list args);
int		ft_parse_input(const char format, va_list args, t_flag flags);
int		ft_align(int size, int cnt);
int		ft_nbr_size(int nbr);
int		ft_zeros(int size, int cnt);

#endif