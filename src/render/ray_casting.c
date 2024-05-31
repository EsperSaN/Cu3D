#include "render.h"

void printray(t_raydata ray)
{
    dprintf(2, "ray_pos x[%d]y[%d]\n", ray.pos.x, ray.pos.y);
}

int ray_casting(mlx_image_t *img, t_data *d)
{
    int             cur_w;
    t_raydata       ray;
    t_player_data   p;
    
    // t_int_point     map;
    // need new var to improve int
    cur_w = 0;
    p = *(d->player);
    // map.x = (int)p.pos.x;
    // map.y = (int)p.pos.y;

    while (cur_w < img->width)
    {
        ray.pos.x = (int)p.pos.x;
        ray.pos.y = (int)p.pos.y;
        ray.is_hit = 0;
        ray.camera.x = 2 * (cur_w / (float)img->width) - 1.0f;
        ray.ray_dir.x = p.dir.x + p.pane.x * ray.camera.x;
        ray.ray_dir.y = p.dir.y + p.pane.y * ray.camera.x;

        if (ray.ray_dir.x == 0)
            ray.ray_dir.x = 1e30;
        if (ray.ray_dir.y == 0)
            ray.ray_dir.y = 1e30;
        ray.delta_distant.x = fabs(1 / ray.ray_dir.x);
        ray.delta_distant.y = fabs(1 / ray.ray_dir.y);
        dprintf(2,"ray dir x[%f] y[%f]\n", ray.ray_dir.x, ray.ray_dir.y);
        dprintf(2,"ray delta x[%f] y[%f]\n", ray.delta_distant.x, ray.delta_distant.y);
        
        if (ray.ray_dir.x < 0)
        {
            ray.step.x = -1;
            ray.side_distant.x = (p.pos.x - ray.pos.x) * ray.delta_distant.x;
        }
        else
        {
            ray.step.x = 1;
            ray.side_distant.x = (ray.pos.x + 1.0 - p.pos.x) * ray.delta_distant.x;
        }
        if (ray.ray_dir.y < 0)
        {
            ray.step.y = -1;
            ray.side_distant.y = (p.pos.y - ray.pos.y) * ray.delta_distant.y;
        }
        else
        {
            ray.step.y = 1;
            ray.side_distant.y = (ray.pos.y + 1.0 - p.pos.y) * ray.delta_distant.y;
        }
        // init done
        while (ray.is_hit == 0)
        {
            if (ray.side_distant.x < ray.side_distant.y)
            {
                ray.side_distant.x += ray.delta_distant.x;
                ray.pos.x += ray.step.x;
                ray.hit_side = 0;
            }
            else
            {
                ray.side_distant.y += ray.delta_distant.y;
                ray.pos.y += ray.step.y;
                ray.hit_side = 1;
            }
            if (d->maps->maps_array[ray.pos.y][ray.pos.x] != '0')
                ray.is_hit = 1;
        }
        if (ray.hit_side == 0)
            ray.perp_wall_distant = (ray.side_distant.x - ray.delta_distant.x);
        else
            ray.perp_wall_distant = (ray.side_distant.y - ray.delta_distant.y);
        
        ray.line_hight = (int)(img->height / ray.perp_wall_distant);

        ray.line_s = (-ray.line_hight / 2) + (img->height / 2);
        if (ray.line_s < 0)
            ray.line_s = 0;
        ray.line_e = (ray.line_hight / 2) + (img->height / 2);
        if (ray.line_e >= img->height)
            ray.line_e = img->height - 1;
        
        if (ray.hit_side == 1)
            ray.color = get_rgba(255, 0, 0, 255);
        else
            ray.color = get_rgba(255,0 ,0, 145);
        dprintf(2, "prep wall [%d] start [%d] end [%d]\n", ray.line_hight, ray.line_s, ray.line_e);
        draw_verline(d->img_game, cur_w, ray.line_s, ray.line_e, ray.color);
        // start texture
        float wallX;

        if (ray.hit_side == 0)
            wallX = p.pos.y + ray.perp_wall_distant * ray.ray_dir.y;
        else
            wallX = p.pos.x + ray.perp_wall_distant * ray.ray_dir.x;
        wallX -= floor(wallX);

        int tex_cor_x = (int)(wallX * (float)d->texture->north_texture->width);
        if (ray.hit_side == 0 && ray.ray_dir.x > 0)
            tex_cor_x = d->texture->north_texture->width - tex_cor_x - 1;
        if (ray.hit_side == 1 && ray.ray_dir.y < 0)
            tex_cor_x = d->texture->north_texture->width - tex_cor_x - 1;
        
        float step_tex;
        step_tex = (d->texture->north_texture->height * 1.0 / ray.line_hight * 1.0);
        float tex_pos = (ray.line_s - img->height / 2 + ray.line_hight / 2) * step_tex;
        int cur_y;
        int tex_cor_y;
        cur_y = ray.line_s;
        while (cur_y < ray.line_e)
        {
            tex_cor_y = (int)tex_pos & (d->texture->north_texture->height - 1);
            tex_pos += step_tex;
            int color = d->texture->north_texture->pixel_array[tex_cor_y][tex_cor_x];
            if (ray.hit_side == 1)
                color = (color >> 1) & 8355711;
            mlx_put_pixel(d->img_game, cur_w, cur_y, color);
            cur_y++;
        }
        cur_w++;
    }
}