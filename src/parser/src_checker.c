#include "parser.h"

int	src_checker(t_parser_data *res)
{
	if (!res->north_texture || !res->south_texture \
	|| !res->west_texture || !res->east_texture \
	|| !res->ceil_color || !res->floor_color)
		return (0);
	if (!is_file_readable(res->north_texture) \
		|| !is_right_extension(res->north_texture, ".png"))
		return (0);
	if (!is_file_readable(res->south_texture) \
		|| !is_right_extension(res->south_texture, ".png"))
		return (0);
	if (!is_file_readable(res->west_texture) \
		|| !is_right_extension(res->west_texture, ".png"))
		return (0);
	if (!is_file_readable(res->east_texture) \
		|| !is_right_extension(res->east_texture, ".png"))
		return (0);
	dprintf(2, "pass src-> checker\n");
	return (1);
}
