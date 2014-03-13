/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:33:19 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 03:37:13 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

int				buttonpress_hook(int button, int x, int y, t_env *env)
{
	t_ray		ray;

	if (button == 1)
		env->pressed_mouse = 1;
	printf("Pressed Button %d at %d, %d\n", button, x, y);
	ray = get_ray_from_point(env, x, y);
	throw_ray(env, &ray);
	if (ray.inter_t != INFINITY)
	{
		if (env->pressed_keys.del)
		{	
			remove_object(env, ray.closest);
			throw_view_plane(env);
			printf("Removed %p\n", ray.closest);
		}
		else
		{
			env->selected_object = ray.closest;
		}
	}
	return (0);
}

int				buttonrelease_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->selected_object = NULL;
		env->pressed_mouse = 0;
	}
	printf("Released Button %d at %d, %d\n", button, x, y);
	return (0);
}

int				motionnotify_hook(int x, int y, t_env *env)
{
	/*
	**	Should check time to reduce lag
	*/
	if (env->pressed_mouse && !env->block_events)
	{
		env->block_events = 1;
		if (env->selected_object)
		{
			vector_add((t_vector*)&(env->selected_object->origin), &env->camera.y_axis, (env->last_mouse_x - x) * 0.1);
			vector_add((t_vector*)&(env->selected_object->origin), &env->camera.z_axis, (env->last_mouse_y - y) * 0.1);
			throw_view_plane(env);
		}
		env->block_events = 0;
	}
	env->last_mouse_x = x;
	env->last_mouse_y = y;
	return (0);
}
