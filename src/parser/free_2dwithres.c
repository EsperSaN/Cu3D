#include "parser.h"

void	free_2dwithres(t_parser_data *res, char **data)
{
	free2d(data);
	free_parser(res);
}
