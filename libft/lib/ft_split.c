/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:12:11 by kzak              #+#    #+#             */
/*   Updated: 2022/09/14 14:07:02 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

static char	**ft_allfree(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static size_t	getsize(char const *s, char c)
{
	size_t	i;
	size_t	size;

	if (!s[0])
		return (0);
	i = 0;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			size++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		size++;
	return (size);
}

static size_t	ft_getlen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	**ft_result(char **res, char const *s, size_t size, char c)
{
	char	*str;
	size_t	i;
	size_t	next_len;

	i = 0;
	str = (char *)s;
	next_len = 0;
	while (i < size)
	{
		while (*str == c)
			str++;
		next_len = ft_getlen(str, c);
		res[i] = (char *)malloc(sizeof(char) * (next_len + 1));
		if (!res[i])
			return (ft_allfree(res));
		ft_strlcpy(res[i], str, next_len + 1);
		str += next_len;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;

	if (!s)
		return (NULL);
	size = getsize(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	return (ft_result(res, s, size, c));
}
