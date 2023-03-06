/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:49:34 by kzak              #+#    #+#             */
/*   Updated: 2022/09/14 14:31:00 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

void	ft_num(const char *str, va_list args, int *j)
{
	int				i;
	unsigned int	k;

	if (*str == 'd' || *str == 'i')
	{
		i = va_arg(args, int);
		ft_putnbr(i, j);
	}
	else if (*str == 'u')
	{
		k = va_arg(args, unsigned int);
		ft_putnbr_u(k, j);
	}
}

void	ft_hex(const char *str, va_list args, int *j)
{
	int				i;
	unsigned int	x;
	unsigned long	a;

	i = 0;
	if (*str == 'x' || *str == 'X')
	{
		x = va_arg(args, unsigned int);
		if (*str == 'x')
			i = 1;
		ft_hex_x(x, i, j);
	}
	else if (*str == 'p')
	{
		a = va_arg(args, unsigned long);
		*j += write(1, "0x", 2);
		ft_hex_p(a, j);
	}
}

void	ft_str(const char *str, va_list args, int *j)
{
	char	*s;
	char	c;
	int		i;

	i = 0;
	if (*str == 's')
	{
		s = va_arg(args, char *);
		if (!s)
		{
			*j += write(1, "(null)", 6);
			return ;
		}
		while (s[i])
			*j += write(1, &s[i++], 1);
	}
	else if (*str == 'c')
	{
		c = va_arg(args, int);
		*j += write(1, &c, 1);
	}
}

void	ft_format(const char *str, va_list args, int *j, int i)
{
	ft_str(&str[i], args, j);
	ft_num(&str[i], args, j);
	ft_hex(&str[i], args, j);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] != '%')
				ft_format(str, args, &j, i);
			else if (str[i])
				j += write(1, &str[i], 1);
		}
		else
			j += write(1, &str[i], 1);
		if (str[i])
			i++;
	}
	return (va_end(args), j);
}
