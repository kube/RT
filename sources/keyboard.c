/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:50:12 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/08 16:22:41 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void		init_pressed_keys(t_pressedkeys *keys)
{
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
	keys->p_up = 0;
	keys->p_down = 0;
}

int			keypress_hook(int keycode, t_pressedkeys *keys)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65363)
		keys->right = 1;
	else if (keycode == 65361)
		keys->left = 1;
	else if (keycode == 65362)
		keys->up = 1;
	else if (keycode == 65364)
		keys->down = 1;
	else if (keycode == 65366)
		keys->p_down = 1;
	return (0);
}

int			is_one_key_pressed(t_pressedkeys *keys)
{
	int		i;
	int		*key;

	i = 0;
	key = (int*)keys;
	while ((size_t)key - (size_t)(keys) < sizeof(*keys))
	{
		if (*key)
			return (1);
		key++;
	}
	return (0);
}

void		check_pressed_keys(t_env *env, t_pressedkeys *keys)
{
	if (env->block_events)
		return ;
	if (keys->up)
		cam_rot_y(&env->camera, -KEYBOARD_PLOT);
	if (keys->down)
		cam_rot_y(&env->camera, KEYBOARD_PLOT);
	if (keys->left)
		cam_rot_z(&env->camera, KEYBOARD_PLOT);
	if (keys->right)
		cam_rot_z(&env->camera, -KEYBOARD_PLOT);
	if (keys->p_up)
		cam_rot_x(&env->camera, -KEYBOARD_PLOT);
	if (keys->p_down)
		cam_rot_x(&env->camera, KEYBOARD_PLOT);
}

int			keyrelease_hook(int keycode, t_pressedkeys *keys)
{
	if (keycode == 65363)
		keys->right = 0;
	else if (keycode == 65361)
		keys->left = 0;
	else if (keycode == 65362)
		keys->up = 0;
	else if (keycode == 65364)
		keys->down = 0;
	else if (keycode == 65366)
		keys->p_down = 0;
	return (0);
}
