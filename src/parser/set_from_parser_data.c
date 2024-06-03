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

int find_player_angle(char p)
{
    // N = 90;
    if (p == 'N')
        return (180);
    if (p == 'S')
        return (0);
    if (p == 'E')
        return (-90);
    if (p == 'W')
        return (90);
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
    int            angle;

    res = ft_calloc(sizeof(t_player_data), 1);
    res->pos = find_player_pos(data->maps->maps_array);
    res->dir.x = 0;
    res->dir.y = 1;
    angle = find_player_angle(data->maps->maps_array[(int)res->pos.y][(int)res->pos.x]);
    res->pane.x = -fabs((tan(get_rad(FIELD_OF_VIEW) / 2)));
    res->pane.y = 0;
    res->dir = rotate_vector(res->dir, angle);
    res->pane = rotate_vector(res->pane, angle);
    data->maps->maps_array[(int)res->pos.y][(int)res->pos.x] = FLOOR;
    res->pos.x += 0.5;
    res->pos.y += 0.5;
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