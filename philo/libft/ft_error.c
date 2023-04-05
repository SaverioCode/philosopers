
#include "libft.h"

void	ft_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	else
		write(2, "Error: <message not setted>.\n", 29);
	exit(1);
}
