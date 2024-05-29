#include "render.h"

t_ray   prepare_ray_for_dda(t_player_data p, int x_cam_pane)
{
    t_ray res;

    res.pos.x = (int)p.pos.x;
    res.pos.y = (int)p.pos.y;
    res.is_hit = 0;
    res.dir.x = p.dir.x + p.pane.x * x_cam_pane;
    res.dir.y = p.dir.y + p.pane.y * x_cam_pane;

    res.delta_dis.x = fabsf(1 / res.dir.x);
    res.delta_dis.y = fabsf(1 / res.dir.y);
    if (res.dir.x == 0)
        res.delta_dis.x = 1e30;
    if (res.dir.y == 0)
        res.delta_dis.y = 1e30;
    if (res.dir.x < 0)
    {
        res.step_inc.x = -1;
        res.side_dist.x = (p.pos.x - res.pos.x) * res.delta_dis.x;
    }
    else
    {
        res.step_inc.x = 1;
        res.side_dist.x = ((res.pos.x + 1.0) - p.pos.x) * res.delta_dis.x;
    }
    if (res.dir.y < 0)
    {
        res.step_inc.y = -1;
        res.side_dist.y = (p.pos.y - res.pos.y) * res.delta_dis.y;
    }
    else
    {
        res.step_inc.y = 1;
        res.side_dist.y = (res.pos.y + 1.0 - p.pos.y) * res.delta_dis.y;
    }
    return (res);
}

#define y_line 0
#define x_line 1

t_ray   dda_till_hit(t_ray r, char **maps)
{
    t_ray ray;

    ray = r;
    while (ray.is_hit == 0)
    {
        if (ray.side_dist.x < ray.side_dist.y)
        {
            ray.side_dist.x += ray.delta_dis.x;
            ray.pos.x += ray.step_inc.x;
            ray.hit_side = x_line;
        }
        else
        {
            ray.side_dist.y += ray.delta_dis.y;
            ray.pos.y += ray.step_inc.y;
            ray.hit_side = y_line;
        }
        if (maps[ray.pos.y][ray.pos.x] != '0')
            ray.is_hit = 1;
    }
    dprintf(2, "check for y [%d] x [%d]\n", ray.pos.y, ray.pos.x);
    dprintf(2, "here at [%c]\n",  maps[ray.pos.y][ray.pos.x]);
    if (ray.hit_side = x_line)
        ray.size = ray.side_dist.x - ray.delta_dis.x;
    else
        ray.size = ray.side_dist.y - ray.delta_dis.y;
    
    return (ray);
}

void project_from_ray(mlx_image_t *img, t_ray ray, int x_to_draw)
{
    int         line_draw_size;
    t_int_point start;
    t_int_point end;
    int         color;

    color = get_rgba(122, 22, 122, 255);

    line_draw_size = (int)(img->height / ray.size);
    start.x = x_to_draw;
    end.x = x_to_draw;
    
    start.y = (int)(((line_draw_size * -1) / 2) + img->height / 2);

    if (start.y < 1)
        start.y = 1;
    end.y = (line_draw_size / 2) + (img->height / 2);

    if (end.y >= img->height)
        end.y = img->height - 1;
    
    if (ray.hit_side == x_line)
        color = color / 2;
    dprintf(2, "start x [%d] y [%d] end x[%d] y[%d]\n", start.x, start.y, end.x, end.y);
    draw_line(img, start, end, color);
}

void printray(t_ray ray)
{
    dprintf(2, "ray_pos x[%d]y[%d]\n", ray.pos.x, ray.pos.y);
}

int ray_casting(mlx_image_t *img, t_data *d)
{
    int             cur_w;
    t_ray           ray;
    float           cam_on_pane;
    t_player_data   p;
    
    cur_w = 0;
    p = *(d->player);
    // while (cur_w <= img->width)
    // {    
    //     cam_on_pane = 2 * cur_w / (float)img->width - 1; // why!!!!
    //     // ray = prepare_ray_for_dda(p, cam_on_pane);
    //     // putreport("prepare done");
    //     // printray(ray);
    //     // ray = dda_till_hit(ray, d->maps->maps_array);
    //     // putreport("DDA done\n");
    //     // printray(ray);
    //     // project_from_ray(img, ray, cur_w);
    //     // cur_w++;
    //     ray.pos.x = (int)p.pos.x;
    //     ray.pos.y = (int)p.pos.y;
    //     ray.dir.x = p.dir.x + p.pane.x * cam_on_pane;
    //     ray.dir.y = p.dir.y + p.pane.y * cam_on_pane;
    //     dprintf(2, "--------------------\nx = [%d]/[%d]\n\ncam = %f\npos = x [%d] y [%d]\nmap x = [%f]\nmap y = [%f]\n dir x [%f] y[%f]\n", cur_w, img->width,cam_on_pane, ray.pos.x,ray.pos.y,p.pos.x, p.pos.y, ray.dir.x, ray.dir.y);
    //     ray.delta_dis.x = fabsf(1 / ray.dir.x);
    //     if (ray.dir.x == 0)
    //         ray.delta_dis.x = 3.4e38;
    //     ray.delta_dis.y = fabsf(1 / ray.dir.y);
    //     if (ray.dir.y == 0)
    //         ray.delta_dis.y = 3.4e38;
        
    //     dprintf(2, "dx = [%f]\ndy = [%f]\n--------------------------\n", ray.delta_dis.x, ray.delta_dis.y);
        
    //     cur_w++;
    // }
}