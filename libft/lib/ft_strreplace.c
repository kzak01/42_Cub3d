/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:00:51 by kzak              #+#    #+#             */
/*   Updated: 2023/03/09 13:10:46 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

char	*ft_strreplace(char *str, char old_char, char new_char)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == old_char && old_char != new_char)
			str[i] = new_char;
	}
	return (str);
}
