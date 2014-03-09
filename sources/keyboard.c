/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:50:12 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/09 17:08:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ft_memory.h>

#include <stdio.h>

void		init_pressed_keys(t_pressedkeys *keys)
{
	ft_bzero(keys, sizeof(*keys));
}

int			keypress_hook(int keycode, t_pressedkeys *keys)
{
	/*
	**	Use allocated table here with Callbacks, Better Performance, Less lines
	*/

	printf("%d\n", keycode);

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
	return (0);
}

int			is_one_key_pressed(t_pressedkeys *keys)
{
	int		i;
	int		*key;

	/*
	**	Maybe would be better with a mask ?
	*/

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
	/*
	**	Use dedicated Key Structure with Callback ?
	**	(Better Perfomance, Less Lines)
	**	Maybe do this in is_one_key_pressed function
	*/

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
	if (keys->num_plus)
		cam_translate(&env->camera, 0, 0, 0.3);
	if (keys->num_minus)
		cam_translate(&env->camera, 0, 0, -0.3);
	if (keys->w)
		cam_translate_vector(&env->camera, &env->camera.x_axis, 0.3);
	if (keys->a)
		cam_translate_vector(&env->camera, &env->camera.y_axis, 0.3);
	if (keys->s)
		cam_translate_vector(&env->camera, &env->camera.x_axis, -0.3);
	if (keys->d)
		cam_translate_vector(&env->camera, &env->camera.y_axis, -0.3);
}

int			keyrelease_hook(int keycode, t_pressedkeys *keys)
{
	/*
	**	Use allocated table here with Callbacks, Better Performance, Less lines
	*/
	
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
	else if (keycode == 65451)
		keys->num_plus = 0;
	else if (keycode == 65453)
		keys->num_minus = 0;
	else if (keycode == 119)
		keys->w = 0;
	else if (keycode == 97)
		keys->a = 0;
	else if (keycode == 115)
		keys->s = 0;
	else if (keycode == 100)
		keys->d = 0;
	else if (keycode == 65535)
		keys->del = 0;
	return (0);
}
