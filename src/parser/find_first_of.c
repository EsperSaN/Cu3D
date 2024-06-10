#include "parser.h"

int find_first_of_space(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (true == ft_isspace(*str))
			return(idx);
		str++;
		idx++;
	}
	return (0);
}
