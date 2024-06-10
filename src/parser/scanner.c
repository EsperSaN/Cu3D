#include "parser.h"

int	in_line(char *str, int start, int stop)
{
	int	i;
	int	f;

	f = 0;
	i = start;
	if (start == stop)
		return (0);
	while (i < stop)
	{
		if (!ft_isspace(str[i]))
			f++;
		i++;
	}
	if (f == 0)
		return (0);
	i = start;
	while (i < stop)
	{
		if (!is_map_element(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	scanner_checker(int num[], int i, char *data)
{
	if (num[0] && !in_line(data, i - num[2] + num[3], i))
		return (1);
	return (0);
}

int	scanner(char *data)
{
	int	i;
	int	num[4];
	bool	isnt_print;

	isnt_print = false;
	i = -1;
	while (i < 4)
		num[i++] = 0;
	i = 0;
	while (data[i])
	{
		// if (false == ft_isprint_mk2(data[i]))
		// {
		// 	isnt_print = true;
		// 	dprintf(2, "the [%c] true\n", data[i]);
		// }
		if (data[i] == '\n')
		{
			num[1] += scanner_checker (num, i, data);
			num[0] = in_line(data, i - num[2] + num[3], i);
			num[2] = 0;
			num[3] = 1;
		}
		num[2]++;
		i++;
	}
	num[1] += scanner_checker (num, i, data);
	num[0] = in_line(data, i - num[2] + num[3], i);
	if ((num[0] + num[1]) > 1)
		return (0);
	return (1);
}
