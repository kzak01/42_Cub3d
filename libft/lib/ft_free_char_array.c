/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:37:14 by kzak              #+#    #+#             */
/*   Updated: 2023/03/07 11:37:15 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

void	ft_free_char_array(char **str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return;
	while (i < len)
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
	str = NULL;
}
