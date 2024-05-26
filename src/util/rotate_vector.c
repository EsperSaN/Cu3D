#include "util.h"

t_float_point rotate_vector(t_float_point vec, float angle)
{
    float radian;
    t_float_point tmp;

    radian = get_rad(angle);
    tmp.x = vec.x;
    tmp.y = vec.y;
    vec.x = tmp.x * cosf(radian) - tmp.y * sinf(radian);
    vec.y = tmp.x * sin(radian) + tmp.y * cosf(radian);
    return (vec);
}