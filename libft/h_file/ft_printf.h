/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:51:56 by kzak              #+#    #+#             */
/*   Updated: 2022/02/11 11:44:52 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_format(const char *str, va_list args, int *j, int i);
void	ft_str(const char *str, va_list args, int *j);
void	ft_hex(const char *str, va_list args, int *j);
void	ft_hex_x(unsigned int x, int i, int *j);
void	ft_hex_p(unsigned long x, int *j);
void	ft_num(const char *str, va_list args, int *j);
void	ft_putnbr(int nb, int *j);
void	ft_putnbr_u(unsigned int n, int *j);

#endif
