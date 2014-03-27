/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pressed_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:52:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 15:58:16 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ft_memory.h>

void				check_pressed_keys(t_pressedkeys *keys)
{
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
