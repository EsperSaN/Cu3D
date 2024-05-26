#include "render.h"

bool init_window(t_data *data)
{
    data->mlx = mlx_init(WIN_WIDTH, WIN_HIGHT, WIN_TITLE, WIN_RESIZE);
    if (data->mlx == NULL)
        return (puterror(MLX_INIT_FAIL), false);
    if (DEMO_MODE == true)
    {
        data->img_game = mlx_new_image(data->mlx, WIN_WIDTH / 2, WIN_HIGHT);
        if (data->img_game == NULL)
            return (puterror(MLX_IMG_FAIL), false);
        data->img_maps = mlx_new_image(data->mlx, WIN_WIDTH / 2, WIN_HIGHT);
        if (data->img_maps == NULL)
            return (puterror(MLX_IMG_FAIL), false);
        if (mlx_image_to_window(data->mlx, data->img_game, 0, 0) == -1 ||\
                mlx_image_to_window(data->mlx, data->img_maps, WIN_WIDTH/2, 0) == -1)
            return (puterror(MLX_IMG_FAIL), false);
    }
    else
    {
        data->img_game = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
        if (data->img_game == NULL || mlx_image_to_window(data->mlx, data->img_game, 0, 0) == -1)
            return (puterror(MLX_IMG_FAIL), false);
    }
    return (true);
}

bool init_event_hook(t_data *data)
{
    //mlx_key_hook(data->mlx, adjust_and_render, (void *)data);
    //mlx_close_hook(data->mlx, terminate_and_cleanup, (void **)&data);
    return (true);
}

bool init_first_frame(t_data *data)
{
    // if (data->img_maps)
    //     clear_image(data->img_maps, data->parser_data->ceil_color);
    // if (data->img_game)
    //     clear_image(data->img_game, data->parser_data->floor_color);
    return (true);
}

bool prepare_render(t_data *data)
{
    if (init_window(data) == false || \
            init_event_hook(data) == false || \
                init_first_frame(data) == false)
        return (false);
    return (true);
}