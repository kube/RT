/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:27:02 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 20:34:15 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <object.h>
#include <pthread.h>
#include <ft_input.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <stdlib.h>
#include <interpreter.h>

static void			add_sphere()
{
	add_object(env->scene, new_object(OBJ_SPHERE));
	env->scene->objects->origin.x = env->scene->camera.origin.x
							+ env->scene->camera.x_axis.x * 4;
	env->scene->objects->origin.y = env->scene->camera.origin.y
							+ env->scene->camera.x_axis.y * 4;
	env->scene->objects->origin.z = env->scene->camera.origin.z
							+ env->scene->camera.x_axis.z * 4;
	env->scene->objects->radius = 1;
	env->scene->objects->color.color = 0xFFFAEFFF;
	env->scene->objects->ambient = 0.2;
	env->scene->objects->diffuse = 0.4;
	env->scene->objects->specular = 0.2;
	env->scene->objects->reflection = 0.7;
	env->last_scene_change = clock();
}

static void			add_cylinder()
{
	add_object(env->scene, new_object(OBJ_CYLINDER));
	env->scene->objects->origin.x = env->scene->camera.origin.x
							+ env->scene->camera.x_axis.x * 4;
	env->scene->objects->origin.y = env->scene->camera.origin.y
							+ env->scene->camera.x_axis.y * 4;
	env->scene->objects->origin.z = env->scene->camera.origin.z
							+ env->scene->camera.x_axis.z * 4;
	env->scene->objects->normal.z = 1;
	env->scene->objects->color.color = 0xFFFFFFFF;
	env->scene->objects->radius = 2.2;
	env->scene->objects->ambient = 0.1;
	env->scene->objects->diffuse = 0.8;
	env->scene->objects->specular = 0.4;
	env->scene->objects->reflection = 0.7;
	env->last_scene_change = clock();
}

static void			add_cone()
{
	add_object(env->scene, new_object(OBJ_CONE));
	env->scene->objects->origin.x = env->scene->camera.origin.x
							+ env->scene->camera.x_axis.x * 4;
	env->scene->objects->origin.y = env->scene->camera.origin.y
							+ env->scene->camera.x_axis.y * 4;
	env->scene->objects->origin.z = env->scene->camera.origin.z
							+ env->scene->camera.x_axis.z * 4;
	env->scene->objects->normal.z = 1;
	env->scene->objects->color.color = 0xFFFFFFFF;
	env->scene->objects->aperture = 22;
	env->scene->objects->ambient = 0.1;
	env->scene->objects->diffuse = 0.8;
	env->scene->objects->specular = 0.4;
	env->scene->objects->reflection = 0.7;
	env->last_scene_change = clock();
}

static void			add_plane()
{
	add_object(env->scene, new_object(OBJ_PLANE));
	env->scene->objects->origin.x = env->scene->camera.origin.x
							+ env->scene->camera.x_axis.x * 4;
	env->scene->objects->origin.y = env->scene->camera.origin.y
							+ env->scene->camera.x_axis.y * 4;
	env->scene->objects->origin.z = env->scene->camera.origin.z
							+ env->scene->camera.x_axis.z * 4;
	env->scene->objects->normal.z = 1;
	env->scene->objects->color.color = 0xFFFFFFFF;
	env->scene->objects->ambient = 0.1;
	env->scene->objects->diffuse = 0.8;
	env->scene->objects->specular = 0.4;
	env->scene->objects->reflection = 0.7;
	env->last_scene_change = clock();
}

static void			add_light()
{
	t_light			*new_light;

	new_light = (t_light *)malloc(sizeof(t_light));
	new_light->type = 0;
	new_light->origin.x = env->scene->camera.origin.x
							+ env->scene->camera.x_axis.x * 4;
	new_light->origin.y = env->scene->camera.origin.y
							+ env->scene->camera.x_axis.y * 4;
	new_light->origin.z = env->scene->camera.origin.z
							+ env->scene->camera.x_axis.z * 4 - 1;
	new_light->intensity = 1.0;
	new_light->color.red = 1.0;
	new_light->color.green = 1.0;
	new_light->color.blue = 1.0;
	new_light->next = env->scene->lights;
	env->scene->lights = new_light;
	env->last_scene_change = clock();
}

void				cmd_add(char **line)
{
	if (*line && !line[1])
	{
		if (ft_strequ("sphere", *line))
			add_sphere();
		else if (ft_strequ("plane", *line))
			add_plane();
		else if (ft_strequ("cylinder", *line))
			add_cylinder();
		else if (ft_strequ("cone", *line))
			add_cone();
		else if (ft_strequ("light", *line))
			add_light();
		else
			ft_putendl("Unrecognized object type.");
	}
	else
		ft_putendl("usage: add <object_type>");
}
