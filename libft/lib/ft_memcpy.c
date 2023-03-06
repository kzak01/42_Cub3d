/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:41 by kzak              #+#    #+#             */
/*   Updated: 2022/09/15 10:17:39 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == src || n == 0)
		return (dst);
	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*new_dst = *new_src;
		i++;
		new_dst++;
		new_src++;
	}
	return (dst);
}
