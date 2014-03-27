/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:42:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 19:44:39 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void			display_camera_properties(t_camera *camera, int file)
{
	ft_putendl_fd("camera:", file);
	dprintf(file, "	x: %f\n", camera->origin.x);
	dprintf(file, "	y: %f\n", camera->origin.y);
	dprintf(file, "	z: %f\n", camera->origin.z);
	dprintf(file, "	x_axisX: %f\n", camera->x_axis.x);
	dprintf(file, "	x_axisY: %f\n", camera->x_axis.y);
	dprintf(file, "	x_axisZ: %f\n", camera->x_axis.z);
	dprintf(file, "	y_axisX: %f\n", camera->y_axis.x);
	dprintf(file, "	y_axisY: %f\n", camera->y_axis.y);
	dprintf(file, "	y_axisZ: %f\n", camera->y_axis.z);
	dprintf(file, "	z_axisX: %f\n", camera->z_axis.x);
	dprintf(file, "	z_axisY: %f\n", camera->z_axis.y);
	dprintf(file, "	z_axisZ: %f\n", camera->z_axis.z);
}

static void			display_sphere_properties(t_object *sphere, int file)
{
	ft_putendl_fd("sphere:", file);
	dprintf(file, "	x: %f\n", sphere->origin.x);
	dprintf(file, "	y: %f\n", sphere->origin.y);
	dprintf(file, "	z: %f\n", sphere->origin.z);
	dprintf(file, "	rotX: %f\n", sphere->rotX);
	dprintf(file, "	rotY: %f\n", sphere->rotY);
	dprintf(file, "	rotZ: %f\n", sphere->rotZ);
	dprintf(file, "	radius: %f\n", sphere->radius);
	dprintf(file, "	color: %X\n", sphere->color.color);
	dprintf(file, "	ambient: %f\n", sphere->ambient);
	dprintf(file, "	diffuse: %f\n", sphere->ambient);
	dprintf(file, "	specular: %f\n", sphere->specular);
	dprintf(file, "	reflection: %f\n", sphere->reflection);
	dprintf(file, "	refraction: %f\n", sphere->refraction);
}

static void			display_plane_properties(t_object *plane, int file)
{
	ft_putendl_fd("plane:", file);
	dprintf(file, "	x: %f\n", plane->origin.x);
	dprintf(file, "	y: %f\n", plane->origin.y);
	dprintf(file, "	z: %f\n", plane->origin.z);
	dprintf(file, "	normX: %f\n", plane->normal.x);
	dprintf(file, "	normY: %f\n", plane->normal.y);
	dprintf(file, "	normZ: %f\n", plane->normal.z);
	dprintf(file, "	radius: %f\n", plane->radius);
	dprintf(file, "	color: %X\n", plane->color.color);
	dprintf(file, "	ambient: %f\n", plane->ambient);
	dprintf(file, "	diffuse: %f\n", plane->ambient);
	dprintf(file, "	specular: %f\n", plane->specular);
	dprintf(file, "	reflection: %f\n", plane->reflection);
	dprintf(file, "	refraction: %f\n", plane->refraction);
}

static void			display_light_properties(t_light *light, int file)
{
	ft_putendl_fd("light:", file);
	dprintf(file, "	x: %f\n", light->origin.x);
	dprintf(file, "	y: %f\n", light->origin.y);
	dprintf(file, "	z: %f\n", light->origin.z);
	dprintf(file, "	intensity: %f\n", light->intensity);
	dprintf(file, "	red: %f\n", light->color.red);
	dprintf(file, "	green: %f\n", light->color.green);
	dprintf(file, "	blue: %f\n", light->color.blue);
}

void				export_scene(int file)
{
	t_object		*object;
	t_light			*light;

	dprintf(file, "render_width: %d\n", env->scene->view_width);
	dprintf(file, "render_height: %d\n", env->scene->view_height);
	dprintf(file, "recursivity: %d\n", env->scene->recursivity);
	dprintf(file, "antialias: %d\n", env->scene->antialias);
	dprintf(file, "diaphragm: %f\n", env->scene->diaphragm);
	display_camera_properties(&env->scene->camera, file);
	light = env->scene->lights;
	while (light)
	{
		display_light_properties(light, file);
		light = light->next;
	}
	object = env->scene->objects;
	while (object)
	{
		if (object->type == OBJ_SPHERE)
			display_sphere_properties(object, file);
		else if (object->type == OBJ_PLANE)
			display_plane_properties(object, file);
		object = object->next;
	}
}
