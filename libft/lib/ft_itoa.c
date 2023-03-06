/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:07:59 by kzak              #+#    #+#             */
/*   Updated: 2022/09/15 10:17:13 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

int	ilen(long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbr;
	int		len;

	nbr = n;
	len = ilen(nbr);
	dest = (char *)malloc((len + 1) * sizeof (char));
	if (!dest)
		return (0);
	dest[len] = '\0';
	if (nbr == 0)
		dest[0] = '0';
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		dest[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (dest);
}
