#include "render.h"

void floor_cast(mlx_image_t *img, int color)
{
    int cur_x;
    int half;
    t_int_point start;
    t_int_point end;

    cur_x = 1;
    start.y = img->height / 2;
    end.y = img->height;

    while (cur_x < img->width)
    {
        start.x = cur_x;
        end.x = cur_x;
        draw_line(img, start, end, color);
        cur_x++;
    }
}