
#include "libft.h"

void	*ft_calloc(size_t bytes)
{
	void	*var;
	char	*tmp;
	size_t	i;

	if (bytes > 16711568)
		ft_error("Error: allocation is to big!\n");
	var = malloc(bytes);
	if (!var)
		ft_error("Error: allocation failed!\n");
	tmp = (char *)var;
	i = 0;
	while (i < bytes)
	{
		tmp[i] = 0;
		i++;
	}
	return (var);
}
