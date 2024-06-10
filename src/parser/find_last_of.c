#include "parser.h"

int find_last_of(char *str, char c)
{
	int len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	len = len - 1;
	while (str[len])
	{
		if (str[len] == c)
			return (len);
		len--;
	}
	return (-1);
}
