#include "render.h"


t_player_data *set_player_data(t_data *data)
{
    t_player_data *res;

    res = ft_calloc(sizeof(t_player_data), 1);
    // res->pos = find_player_pos(data->maps->maps_array);
    return (res);
}

bool set_from_parser_data(t_data *data)
{
    int i;

    data->maps = set_maps_data(data);
    if (data->maps == NULL)
        return (false);
    data->texture = set_texture_assets(data);
    if (data->texture == NULL)
        return (false);
    data->player = set_player_data(data);
    if (data->player == NULL)
        return (false);
    return (true);

}
