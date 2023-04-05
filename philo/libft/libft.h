
#ifndef	LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(char *str);
int		ft_numlen(long long num, int base);
void	ft_error(char *str);
void	*ft_calloc(size_t bytes);
char	*ft_itoa(long long num);

#endif
