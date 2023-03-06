/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:36:51 by kzak              #+#    #+#             */
/*   Updated: 2023/03/04 19:43:28 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

long int	ft_atol(const char *str)
{
	long int result = 0;
	int sign = 1;

	// skip leading white space
	while (ft_isspace(*str))
		str++;

	// handle sign
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	// convert digits to integer
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (sign * result);
}
