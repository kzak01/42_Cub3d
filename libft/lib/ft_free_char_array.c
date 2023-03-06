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
