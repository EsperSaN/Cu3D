#include "parser.h"

int	is_numline(char *str)
{
	int			i;
	int			co;

	co = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			co++;
		else if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	if (co > 2)
		return (0);
	dprintf(2, "[%s] << pass numline \n", str);
	return (1);
}
