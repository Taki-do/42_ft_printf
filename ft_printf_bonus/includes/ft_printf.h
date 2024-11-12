/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:09:20 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/11 16:34:18 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int hexa;
	int	space;
	int	sign;
}	t_flag;

int		ft_printf(const char *format, ...);
int		ft_printaddr(void *addr);
int		ft_putnbr_len(int nb, t_flag fl, const char format);
int		ft_putunbr_len(unsigned int nb);
int		ft_putchar_len(const char c);
int		ft_putstr_len(const char *str);
int		ft_printaddr(void *addr);
int		ft_hexa_len(unsigned int dec, int ul, t_flag fl, const char format);
int		ft_put_flags(t_flag flag, const char format);

#endif