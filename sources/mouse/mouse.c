/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:33:19 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 22:20:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_math.h>
#include <ft_print.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

int				mousepress_ev(int button, int x, int y, t_env *env)
{
	t_ray		ray;

	printf("Pressed Button %d at %d, %d\n", button, x, y);
	ray = get_ray_from_point(env, x, y);
	throw_ray(env, &ray, 0, NULL);
	if (button == 1)
		env->pressed_mouse = 1;
	if (ray.inter_t != INFINITY)
	{

		if (button == 1 && env->pressed_keys.del)
		{
			remove_object(env->scene, ray.closest);
			update_image(env);
			printf("Removed %p\n", ray.closest);
		}
		else
		{
			if (button == 3)
			{
				ft_putstr("Selected object ");
				ft_putunbr((unsigned int)ray.closest);
				ft_putendl(".");
			}
			env->selected_object = ray.closest;
		}
	}
	return (0);
}

int				mouserelease_ev(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->selected_object = NULL;
		env->pressed_mouse = 0;
	}
	printf("Released Button %d at %d, %d\n", button, x, y);
	env->refresh_image = 1;
	return (0);
}

int				motionnotify_ev(int x, int y, t_env *env)
{
	float		coeff;

	if (env->pressed_mouse)
	{
		if (env->selected_object)
		{
			coeff = distance_between_points(&env->selected_object->origin,
				&env->scene->camera.origin) * 0.001;
			if (env->pressed_keys.alt)
			{
				env->selected_object->radius +=
					fmin((float)(x - env->mouse_x), (float)(y - env->mouse_y)) * coeff;
				if (env->selected_object->radius < 0)
					env->selected_object->radius = -env->selected_object->radius;
			}
			else
			{
				vector_add((t_vector*)&(env->selected_object->origin),
					&env->scene->camera.y_axis, (env->mouse_x - x) * coeff);
				if (env->pressed_keys.ctrl)
					vector_add((t_vector*)&(env->selected_object->origin),
						&env->scene->camera.x_axis, (env->mouse_y - y) * coeff);
				else
					vector_add((t_vector*)&(env->selected_object->origin),
						&env->scene->camera.z_axis, (env->mouse_y - y) * coeff);
			}
			env->refresh_image = 1;
		}
	}
	env->mouse_x = x;
	env->mouse_y = y;
	return (0);
}
