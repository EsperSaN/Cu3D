#include "parser.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_map_element(str[i]))
			return (0);
		i++;
	}
	return (1);
}