#include "parser.h"

int	is_map_element(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' \
		|| c == 'N' || c == '0' || c == '1' || c == ' ')
		return (1);
	return (0);
}