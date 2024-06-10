#include "parser.h"

int	scan4player(char **map)
{
	int	i;
	int	j;
	int	co;

	i = 0;
	co = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N')
				co++;
			if (map[i][j] == 'E' || map[i][j] == 'S')
				co++;
			j++;
		}
		i++;
	}
	if (co > 1 || co == 0)
		return (0);
	return (1);
}
