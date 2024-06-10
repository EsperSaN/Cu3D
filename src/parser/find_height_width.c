#include "parser.h"

int	find_height(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i - 6);
}

int	find_width(char **data)
{
	int	i;
	int	s;
	int	max;

	max = 0;
	i = 6;
	s = 0;
	while (data[i])
	{
		s = ft_strlen(data[i]);
		if (s > max)
			max = s;
		i++;
	}
	return (max);
}
