/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:28:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 16:43:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_math.h>
#include <math.h>

int				motionnotify_ev(int x, int y)
{
	float		coeff;

	if (env->block_events)
		return (0);
	if (env->pressed_mouse)
	{
		if (env->selected_object)
		{
			coeff = distance_between_points(&env->selected_object->origin,
				&env->scene->camera.origin) * 0.001;
			if (env->pressed_keys.alt)
			{
				env->selected_object->radius +=
					fmin((float)(x - env->mouse_x), (float)(y - env->mouse_y))
						* coeff;
				if (env->selected_object->radius < 0)
					env->selected_object->radius *= -1;
			}
			else if (env->pressed_keys.tab)
			{
				normalize_vector(&env->selected_object->normal);
				vect_rot_x(&env->selected_object->normal, -cos(x - env->mouse_x)
							/ (5000 * coeff));
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
		}
		env->last_scene_change = clock();
	}
	env->mouse_x = x;
	env->mouse_y = y;
	return (0);
}
