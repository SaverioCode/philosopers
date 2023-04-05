
int	ft_numlen(long long num, int base)
{
	int	counter;

	if (base < 2)
		ft_error("Error: number base to low!\n");
	counter = 0;
	if (num < 0)
	{
		num *= -1;
		counter++;
	}
	while (num > 0)
	{	
		num /= base;
		counter++;
	}
	return (counter);
}
