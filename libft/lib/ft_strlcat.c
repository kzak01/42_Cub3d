/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:20:28 by kzak              #+#    #+#             */
/*   Updated: 2022/09/14 14:07:18 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst[a] && a < dstsize)
		a++;
	while ((src[b]) && ((a + b + 1) < dstsize))
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a != dstsize)
		dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
