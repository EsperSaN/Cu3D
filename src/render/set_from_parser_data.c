#include "render.h"

bool is_in_set(char *set, char c)
{
    while (*set)
    {
        if (c == *set)
            return (true);
        set++;
    }
    return (false);
}

t_float_point find_player_dir(char p)
{
    t_float_point res;
    
    res.x = 0;
    res.y = 0;
    if (p == 'N')
        res.y = -1;
    if (p == 'S')
        res.y = 1;
    if (p == 'E')
        res.x = -1;
    if (p == 'W')
        res.x = 1;
    return (res);
}

t_float_point find_player_pos(char **maps)
{
    t_float_point res;

    res.y = 0;
    while (maps[(int)res.y])
    {
        res.x = 0;
        while (maps[(int)res.y][(int)res.x])
        {
            if (is_in_set("NSWE", maps[(int)res.y][(int)res.x]))
                return (res);
            res.x += 1;
        }
        res.y += 1;
    }
    return (res);
}

t_player_data *set_player_data(t_data *data)
{
    t_player_data *res;

    res = ft_calloc(sizeof(t_player_data), 1);
    res->pos = find_player_pos(data->maps->maps_array);
    res->dir = find_player_dir(data->maps->maps_array[(int)res->pos.y][(int)res->pos.x]);
    return (res);
}

bool set_from_parser_data(t_data *data)
{
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
