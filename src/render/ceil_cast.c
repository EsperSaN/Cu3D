#include "render.h"

void ceil_cast(mlx_image_t *img, int color)
{
    int cur_x;
    int half;
    t_int_point start;
    t_int_point end;

    cur_x = 1;
    end.y = img->height / 2;
    start.y = 0;
    while (cur_x < img->width)
    {
        start.x = cur_x;
        end.x = cur_x;
        draw_line(img, start, end, color);
        cur_x++;
    }
}