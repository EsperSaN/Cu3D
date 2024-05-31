#include "render.h"

t_maps_data *set_maps_data(t_data *data)
{
    t_maps_data *res;
    int         i;

    res = ft_calloc(sizeof(t_maps_data), 1);
    if (res == NULL)
        return (NULL);
    res->maps_array = ft_calloc(sizeof(char *), data->parser_data->height + 1);
    if (res->maps_array == NULL)
    {
        free(res);
        return (NULL);
    }
    i = 0;
    while (data->parser_data->maps_data[i])
    {
        res->maps_array[i] = \
                ft_strdup(data->parser_data->maps_data[i]);
        if (res->maps_array[i] == NULL)
        {
            free2d(res->maps_array);
            free(res);
            return(NULL);
        }
        dprintf(2, "[%s]\n", res->maps_array[i]);
        i++;
    }
    res->maps_width = data->parser_data->width;
    res->maps_height = data->parser_data->height;
    return (res);
}