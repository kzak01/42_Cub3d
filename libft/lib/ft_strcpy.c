/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:24:01 by kzak              #+#    #+#             */
/*   Updated: 2023/03/09 13:10:14 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_start;

	dst_start = dst;
	while (*src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst_start);
}
