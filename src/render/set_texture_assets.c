#include "render.h"

t_texture_assets *set_texture_assets(t_data *data)
{
    t_texture_assets *res;

    res = ft_calloc(sizeof(t_texture_assets), 1);
    if (res == NULL)
        return(NULL);
    res->ceil_color = data->parser_data->ceil_color;
    res->floor_color = data->parser_data->floor_color;
    res->east_texture = get_texture_png(data->parser_data->east_texture);
    res->west_texture = get_texture_png(data->parser_data->west_texture);
    res->north_texture = get_texture_png(data->parser_data->north_texture);
    res->south_texture = get_texture_png(data->parser_data->south_texture);
    return (res);
}
