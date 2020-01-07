#include "../inc/fdf.h"

int	ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

int	ft_min(int a, int b)
{
	return (a <= b ? a : b);
}

int	ft_max(int a, int b)
{
	return (a >= b ? a : b);
}