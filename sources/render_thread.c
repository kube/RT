/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:53:59 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/04/19 09:07:54 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_print.h>
#include <ft_memory.h>
#include <stdlib.h>
#include <math.h>

static void			display_ray(t_light_color color,
								unsigned int i, unsigned int j)
{
	color.r /= env->scene->antialias * env->scene->antialias;
	color.g /= env->scene->antialias * env->scene->antialias;
	color.b /= env->scene->antialias * env->scene->antialias;
	light_to_render(i, j, &color);
}

static void			send_pixel_rays(unsigned int x, unsigned int y)
{
	float			i;
	float			j;
	t_ray			ray;
	t_light_color	dot;

	ft_bzero(&dot, sizeof(dot));
	j = 0;
	while (j < env->scene->antialias)
	{
		i = 0;
		while (i < env->scene->antialias)
		{
			ray = get_ray_from_point(((float)x + (i / env->scene->antialias)),
									((float)y + (j / env->scene->antialias)));
			throw_ray(&ray, 1, 0, env->scene->recursivity);
			dot.r += ray.color.r;
			dot.g += ray.color.g;
			dot.b += ray.color.b;
			i++;
		}
		j++;
	}
	display_ray(dot, x, y);
}

static void			send_fast_rays(unsigned int x, unsigned int y)
{
	t_ray			ray;

	if (x % FAST_RENDER_PRECISION || y % FAST_RENDER_PRECISION)
		return ;
	ray = get_ray_from_point((float)x, (float)y);
	throw_ray(&ray, 1, 0, 0);
	fast_light_to_render(x, y, &ray.color);
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
			if (env->fast_mode)
				send_fast_rays(i, j);
			else
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
