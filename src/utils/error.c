#include "utils.h"

int	error(char *str)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", str);
	return (1);
}
