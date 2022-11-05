#include "utils.h"

double	get_double(char *str_double)
{
	double	res;
	char	**split_by_decimal;

	split_by_decimal = ft_split(str_double,  '.');
	res = ft_atoi(split_by_decimal[0]);
	if (split_by_decimal[1])
		res += (double)ft_atoi(split_by_decimal[1]) / 10;
	free_darray(split_by_decimal);
	return (res);
}