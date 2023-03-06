/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:12:14 by kzak              #+#    #+#             */
/*   Updated: 2022/09/14 14:31:06 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

void	ft_hex_x(unsigned int x, int i, int *j)
{
	if (x >= 16)
	{
		ft_hex_x(x / 16, i, j);
		ft_hex_x(x % 16, i, j);
	}
	else
	{
		if (i == 0)
			*j += write(1, &"0123456789ABCDEF"[x], 1);
		else if (i == 1)
			*j += write(1, &"0123456789abcdef"[x], 1);
	}
}

void	ft_hex_p(unsigned long x, int *j)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (x >= 16)
		ft_hex_p(x / 16, j);
	*j += write(1, &hex[x % 16], 1);
}

void	ft_putnbr(int nb, int *j)
{
	char	*num;

	num = "0123456789";
	if (nb == -2147483648)
	{
		*j += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		*j += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, j);
	*j += write(1, &num[nb % 10], 1);
}

void	ft_putnbr_u(unsigned int n, int *j)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, j);
		ft_putnbr_u(n % 10, j);
	}
	else
		*j += write(1, &"0123456789"[n], 1);
}
