/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:37:33 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/04/19 09:06:17 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <mlx.h>

void				light_to_render(int x, int y,
									t_light_color *light)
{
	unsigned int	i;

	i = env->scene->view_width * (unsigned int)y + (unsigned int)x;
	if (i < env->scene->view_width * env->scene->view_height && (int)y >= 0
		&& (int)x >= 0 && (unsigned int)x < env->scene->view_width)
	{
		env->rendering[i].red = light->red;
		env->rendering[i].green = light->green;
		env->rendering[i].blue = light->blue;
	}
}

void				fast_light_to_render(int x, int y,
									t_light_color *light)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;

	k = env->scene->view_width * (unsigned int)y + (unsigned int)x;
	if (k < env->scene->view_width * env->scene->view_height && (int)y >= 0
		&& (int)x >= 0 && (unsigned int)x < env->scene->view_width)
	{
		j = 0;
		while (j < FAST_RENDER_PRECISION)
		{
			i = 0;
			while (i < FAST_RENDER_PRECISION)
			{
				l = k + i + j * env->scene->view_width;
				env->rendering[l].red = light->red;
				env->rendering[l].green = light->green;
				env->rendering[l].blue = light->blue;
				i++;
			}
			j++;
		}
	}

}

void				clean_light_on_render(int x, int y)
{
	unsigned int	i;

	i = env->scene->view_width * (unsigned int)y + (unsigned int)x;
	if (i < env->scene->view_width * env->scene->view_height && (int)y >= 0
		&& (int)x >= 0 && (unsigned int)x < env->scene->view_width)
	{
		env->rendering[i].red = 0;
		env->rendering[i].green = 0;
		env->rendering[i].blue = 0;
	}
}

void				render_to_image()
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < env->scene->view_height)
	{
		x = 0;
		while (x < env->scene->view_width)
		{
			pixel_to_image(x, y,
				light_diaphragm(&env->rendering[y * env->scene->view_width + x],
					env->scene->diaphragm));
			x++;
		}
		y++;
	}
	env->last_image_refresh = clock();
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
