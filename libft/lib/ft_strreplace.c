/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:00:51 by kzak              #+#    #+#             */
/*   Updated: 2023/03/05 12:26:32 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

	// size_t	len;
	// char	*new_str;
	// size_t	i;

	// len = ft_strlen(str);
	// new_str = malloc(len + 1);
	// i = -1;
	// if (!str)
	// 	return NULL;
	// while (str[++i])
	// {
	// 	if (str[i] == old_char)
	// 		new_str[i] = new_char;
	// 	else
	// 		new_str[i] = str[i];
	// }
	// new_str[len] = '\0';
	// return (new_str);
char	*ft_strreplace(char *str, char old_char, char new_char)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == old_char && old_char != new_char)
		{
		str[i]=new_char;
		}
	}
	return (str);
}
