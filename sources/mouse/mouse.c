/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:33:19 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 02:53:09 by cfeijoo          ###   ########.fr       */
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

	printf("Pressed Button %d at %d, %d\n", button, x, y);
	if (env->pressed_keys.del)
	{
		ray = get_ray_from_point(env, x, y);
		throw_ray(env, &ray);
		if (ray.inter_t != INFINITY)
		{
			remove_object(env, ray.closest);
			throw_view_plane(env);
			printf("Removed %p\n", ray.closest);
		}
	}
	return (0);
}
