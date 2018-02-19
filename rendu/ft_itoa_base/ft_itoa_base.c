#include <stdlib.h>

void	itoa_base(int value, int base, char **result, int *index)
{
	const char *b = "0123456789abcdef";
	int			a;

	if (value >= base || value <= (base * -1))
		itoa_base(value / base, base, result, index);
	a = value % base;
	if (a < 0)
		a = a * -1;
	(*result)[(*index)] = b[a];
	(*index)++;
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	int		index;

	if (base < 2 && base <16)
		return (NULL);
	result = (char *)malloc(sizeof(char) * 35);
	index = 0;
	if (base == 10 && value < 0)
	{
		result[0] = '-';
		index = 1;
	}
	if (result == NULL)
		return (NULL);
	itoa_base(value, base, &result, &index);
	result[index] = '\0';
	return (result);
}