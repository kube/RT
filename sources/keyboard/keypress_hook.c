/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:51:23 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 16:03:34 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ft_memory.h>

int			keypress_hook(int keycode, t_pressedkeys *keys)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 61)
	{
		env->scene->diaphragm *= 1.05;
		env->last_light_refresh = clock();
	}
	else if (keycode == 45)
	{
		env->scene->diaphragm /= 1.05;
		env->last_light_refresh = clock();
	}
	else if (env->block_events)
		return (0);
	else if (keycode == 65363)
		keys->right = 1;
	else if (keycode == 65361)
		keys->left = 1;
	else if (keycode == 65362)
		keys->up = 1;
	else if (keycode == 65364)
		keys->down = 1;
	else if (keycode == 65365)
		keys->p_up = 1;
	else if (keycode == 65366)
		keys->p_down = 1;
	else if (keycode == 65451)
		keys->num_plus = 1;
	else if (keycode == 65453)
		keys->num_minus = 1;
	else if (keycode == 119)
		keys->w = 1;
	else if (keycode == 97)
		keys->a = 1;
	else if (keycode == 115)
		keys->s = 1;
	else if (keycode == 100)
		keys->d = 1;
	else if (keycode == 65535)
		keys->del = 1;
	else if (keycode == 65507)
		keys->ctrl = 1;
	else if (keycode == 65289)
		keys->tab = 1;
	else if (keycode == 32)
	{
		if (env->selected_object)
			duplicate_object(env->selected_object);
	}
	else if (keycode == 65406 || keycode == 65513)
		keys->alt = 1;
	return (0);
}
