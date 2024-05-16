#include "./render.h"

# define WIN_WIDTH 800
# define WIN_HIGHT 800
# define WIN_TITLE "RAY CASTING"
# define WIN_RESIZE false
# define MLX_INIT_FAIL "MLX INIT FAIL : EXIT"
# define MLX_IMG_FAIL "MLX FAIL TO CREATE IMG"
# define DEMO_MODE true

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
    }
    else
    {
        data->img_game = mlx_new_image(data->mlx, WIN_WIDTH / 2, WIN_HIGHT);
        if (data->img_game == NULL)
            return (puterror(MLX_IMG_FAIL), false);
    }
    mlx_image_t *text = mlx_put_string(data->mlx, "LOADING....", data->img_game->width/2, data->img_game->height /2);
    mlx_image_to_window(data->mlx, text, 0 ,0);
    mlx_image_to_window(data->mlx, data->img_game, 0, 0);
}

bool init_first_frame(t_data *data)
{

}

bool prepare_render(t_data *data)
{
    init_window(data);
    init_first_frame(data);
	mlx_image_to_window(data->mlx, data->img_game, 0, 0);
    return (true);
}