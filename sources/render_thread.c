/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:53:59 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/21 23:12:24 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_print.h>
#include <stdlib.h>
#include <math.h>


#include <stdio.h>

#define PREDEFINED_RENDER_PLOT	9

static void			display_ray(t_ray *ray,
								unsigned int i, unsigned int j)
{
	if (ray->inter_t != INFINITY && !env->pressed_keys.shift)
		light_to_render(i, j, &ray->color);
	else if (ray->inter_t != INFINITY)
		pixel_to_image(i, j, ray->closest->color.color);
	else if (env->pressed_keys.shift)
		pixel_to_image(i, j, 0x00000000);
	else
		clean_light_on_render(i, j);
}

static void			*throw_view_plane(void *thread_input)
{
	t_thread_input	*input;
	unsigned int	i;
	unsigned int	j;
	t_ray			ray;

	input = (t_thread_input*)thread_input;
	env->last_light_refresh = clock();
	j = input->y1;
	while (j <= input->y2)
	{
		i = input->x1;
		while (i <= input->x2)
		{
			ray = get_ray_from_point(i, j);
			throw_ray(&ray, !env->pressed_keys.shift, NULL, env->scene->recursivity);
			display_ray(&ray, i++, j);
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
