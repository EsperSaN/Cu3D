/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_png_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:31:14 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 15:23:08 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	copy_texture_prop(mlx_texture_t *m_tex, t_texture *ret)
{
	unsigned int	i;
	unsigned int	cur_b;
	unsigned int	j;

	i = 0;
	cur_b = 0;
	while (i < m_tex->height)
	{
		j = 0;
		while (j < m_tex->width)
		{
			ret->pixel_array[i][j] = get_rgba(m_tex->pixels[cur_b], \
				m_tex->pixels[cur_b + 1], m_tex->pixels[cur_b + 2], \
				m_tex->pixels[cur_b + 3]);
			cur_b += m_tex->bytes_per_pixel;
			j++;
		}
		i++;
	}
	ret->width = m_tex->width;
	ret->height = m_tex->height;
}

static bool	check_init(char *tex_file, mlx_texture_t **m_tex, t_texture **ret)
{
	if (!is_file_valid(tex_file, ".png"))
		return (puterror("wrong texture file ext"), false);
	*ret = ft_calloc(sizeof(t_texture), 1);
	if (ret == NULL)
		return (puterror("Malloc error"), false);
	*m_tex = mlx_load_png(tex_file);
	if (*m_tex == false)
		return (puterror("Texture Cannot load"), free(*ret), false);
	if ((*m_tex)->height != (*m_tex)->width)
		return (puterror("Texture should be Square!!!"), \
				free(*ret), mlx_delete_texture(*m_tex), false);
	(*ret)->pixel_array = ft_calloc(sizeof(int *), (*m_tex)->height);
	if ((*ret)->pixel_array == NULL)
		return (free(*ret), mlx_delete_texture(*m_tex), false);
	return (true);
}

t_texture	*get_texture_png(char *tex_file)
{
	mlx_texture_t	*m_tex;
	t_texture		*ret;
	unsigned int	i;

	m_tex = NULL;
	ret = NULL;
	if (check_init(tex_file, &m_tex, &ret) == false)
		return (NULL);
	i = 0;
	while (i < m_tex->height)
	{
		ret->pixel_array[i] = ft_calloc(sizeof(int), m_tex->width);
		if (ret->pixel_array[i] == NULL)
			return (free_texture2(ret, i), \
						mlx_delete_texture(m_tex), NULL);
		i++;
	}
	copy_texture_prop(m_tex, ret);
	mlx_delete_texture(m_tex);
	return (ret);
}
