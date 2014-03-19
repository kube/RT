/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:50:12 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 22:51:17 by cfeijoo          ###   ########.fr       */
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

	printf("Press %d\n", keycode);

	if (env->block_events)
		return (0);

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
	else if (keycode == 65505)
		keys->shift = 1;
	else if (keycode == 65507)
		keys->ctrl = 1;
	else if (keycode == 65289)
		keys->tab = 1;
	else if (keycode == 32)
	{
		if (env->selected_object)
			duplicate_object(env->selected_object);
	}
	else if (keycode == 61)
		env->scene->diaphragm *= 1.05;
	else if (keycode == 45)
		env->scene->diaphragm /= 1.05;
	else if (keycode == 65406)
		keys->alt = 1;
	return (0);
}

int				is_one_key_pressed(t_pressedkeys *keys)
{
	int			i;
	int			*key;
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

void				check_pressed_keys(t_pressedkeys *keys)
{
	/*
	**	Use dedicated Key Structure with Callback ?
	**	(Better Perfomance, Less Lines)
	**	Maybe do this in is_one_key_pressed function
	*/

	if (keys->up)
		cam_rot_y(&env->scene->camera, -KEYBOARD_ROT_PLOT);
	if (keys->down)
		cam_rot_y(&env->scene->camera, KEYBOARD_ROT_PLOT);
	if (keys->left)
		cam_rot_z(&env->scene->camera, KEYBOARD_ROT_PLOT);
	if (keys->right)
		cam_rot_z(&env->scene->camera, -KEYBOARD_ROT_PLOT);
	if (keys->p_up)
		cam_rot_x(&env->scene->camera, -KEYBOARD_ROT_PLOT);
	if (keys->p_down)
		cam_rot_x(&env->scene->camera, KEYBOARD_ROT_PLOT);
	if (keys->num_plus)
		cam_translate(&env->scene->camera, 0, 0, KEYBOARD_MOV_PLOT);
	if (keys->num_minus)
		cam_translate(&env->scene->camera, 0, 0, -KEYBOARD_MOV_PLOT);
	if (keys->w)
	{
		if (env->selected_object)
			vector_add((t_vector*)&(env->selected_object->origin),
				&env->scene->camera.x_axis, KEYBOARD_MOV_PLOT);
		cam_translate_vector(&env->scene->camera, &env->scene->camera.x_axis,
			KEYBOARD_MOV_PLOT);
	}
	if (keys->a)
	{
		if (env->selected_object)
			vector_add((t_vector*)&(env->selected_object->origin),
				&env->scene->camera.y_axis, KEYBOARD_MOV_PLOT);
		cam_translate_vector(&env->scene->camera, &env->scene->camera.y_axis,
			KEYBOARD_MOV_PLOT);
	}
	if (keys->s)
	{
		if (env->selected_object)
			vector_add((t_vector*)&(env->selected_object->origin),
				&env->scene->camera.x_axis, -KEYBOARD_MOV_PLOT);
		cam_translate_vector(&env->scene->camera, &env->scene->camera.x_axis,
			-KEYBOARD_MOV_PLOT);
	}
	if (keys->d)
	{
		if (env->selected_object)
			vector_add((t_vector*)&(env->selected_object->origin),
			&env->scene->camera.y_axis, -KEYBOARD_MOV_PLOT);
		cam_translate_vector(&env->scene->camera, &env->scene->camera.y_axis,
			-KEYBOARD_MOV_PLOT);
	}
	env->last_scene_change = clock();
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
	else if (keycode == 65365)
		keys->p_up = 0;
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
	else if (keycode == 32)
		keys->space = 0;
	else if (keycode == 65505)
		keys->shift = 0;
	else if (keycode == 65507)
		keys->ctrl = 0;
	else if (keycode == 65289)
		keys->tab = 0;
	else if (keycode == 65406)
		keys->alt = 0;
	return (0);
}
