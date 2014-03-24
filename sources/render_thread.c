/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:53:59 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 23:56:03 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_print.h>
#include <stdlib.h>
#include <math.h>


#include <stdio.h>

#define PREDEFINED_RENDER_PLOT	9

static void			display_ray(t_light_color color,
								unsigned int i, unsigned int j)
{
	// if (!env->pressed_keys.shift)
	light_to_render(i, j, &color);
	// else if (ray->inter_t != INFINITY)
	// 	pixel_to_image(i, j, ray->closest->color.color);
	// else if (env->pressed_keys.shift)
	// 	pixel_to_image(i, j, 0x00000000);
}

static void			send_pixel_rays(unsigned int x, unsigned int y)
{
	float			i;
	float			j;
	t_ray			ray;
	t_light_color	dot;

	dot.r = 0.0;
	dot.g = 0.0;
	dot.b = 0.0;
	j = 0;
	while (j < env->scene->antialiasing)
	{
		i = 0;
		while (i < env->scene->antialiasing)
		{
			ray = get_ray_from_point(((float)x + (i / env->scene->antialiasing)),
									((float)y + (j / env->scene->antialiasing)));
			throw_ray(&ray, !env->pressed_keys.shift, 0, env->scene->recursivity);
			dot.r += ray.color.r;
			dot.g += ray.color.g;
			dot.b += ray.color.b;
			i++;
		}
		j++;
	}
	display_ray(dot, x, y);
}

static void			*throw_view_plane(void *thread_input)
{
	t_thread_input	*input;
	unsigned int	i;
	unsigned int	j;

	input = (t_thread_input*)thread_input;
	env->last_light_refresh = clock();
	j = input->y1;
	while (j <= input->y2)
	{
		i = input->x1;
		while (i <= input->x2)
		{
			send_pixel_rays(i, j);
			i++;
		}
		j++;
	}
	env->running_threads--;
	free(thread_input);
	return (NULL);
}

int					create_render_thread(t_thread_input *input)
{
	env->running_threads++;
	if (pthread_create(&env->render_threads[input->thread_number], NULL,
		throw_view_plane, (void*)input))
	{
		ft_putendl_fd("ERROR! Unable to create render thread.", 2);
		return (1);
	}
	return (0);
}
