/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:10:43 by kzak              #+#    #+#             */
/*   Updated: 2023/03/09 13:11:11 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

size_t	ft_strspn(const char *str, const char *chars)
{
	size_t		count;
	const char	*p;
	const char	*q;

	count = 0;
	p = str;
	while (*p != '\0')
	{
		q = chars;
		while (*q != '\0' && *q != *p)
			q++;
		if (*q == '\0')
			return (count);
		p++;
		count++;
	}
	return (count);
}
