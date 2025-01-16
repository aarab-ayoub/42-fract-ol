#include "fractol.h"

double	ft_atof(const char *str)
{
	double result = 0.0, fraction = 1.0;
	int sign = 1;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
			result = result * 10.0 + (*str++ - '0'), fraction *= 10.0;
	}
	return (sign * result / fraction);
}