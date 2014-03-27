/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:33:19 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 16:30:20 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <ft_math.h>
#include <ft_print.h>
#include <math.h>
#include <stdlib.h>

int				mousepress_ev(int button, int x, int y)
{
	t_ray		ray;

	if (env->block_events)
		return (0);
	ray = get_ray_from_point(x, y);
	throw_ray(&ray, 0, NULL, 0);
	if (button == 1)
		env->pressed_mouse = 1;
	if (ray.inter_t != INFINITY)
	{
		if (button == 1 && env->pressed_keys.del)
		{
			remove_object(env->scene, ray.closest);
			update_image(env);
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

int				mouserelease_ev(int button, int x, int y)
{
	(void)x;
	(void)y;
	if (env->block_events)
		return (0);
	if (button == 1 || button == 0)
	{
		env->selected_object = NULL;
		env->pressed_mouse = 0;
	}
	return (0);
}
