/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:18:22 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/07 12:08:38 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printaddr(void *addr);
int		ft_putnbr_len(int nb);
int		ft_putunbr_len(unsigned int nb);
int		ft_putchar_len(const char c);
int		ft_putstr_len(const char *str);
int		ft_inhex(unsigned char print);
int		ft_printaddr(void *addr);
int		ft_hexa_len(unsigned int dec, int ul);

#endif