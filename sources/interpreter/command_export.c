/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 16:44:00 by cfeijoo          ###   ########.fr       */
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
	ft_putendl_fd("	camera:", file);
	dprintf(file, "		x: %f\n", camera->origin.x);
	dprintf(file, "		y: %f\n", camera->origin.y);
	dprintf(file, "		z: %f\n", camera->origin.z);
	dprintf(file, "		x_axisX: %f\n", camera->x_axis.x);
	dprintf(file, "		x_axisY: %f\n", camera->x_axis.y);
	dprintf(file, "		x_axisZ: %f\n", camera->x_axis.z);
	dprintf(file, "		y_axisX: %f\n", camera->y_axis.x);
	dprintf(file, "		y_axisY: %f\n", camera->y_axis.y);
	dprintf(file, "		y_axisZ: %f\n", camera->y_axis.z);
	dprintf(file, "		z_axisX: %f\n", camera->z_axis.x);
	dprintf(file, "		z_axisY: %f\n", camera->z_axis.y);
	dprintf(file, "		z_axisZ: %f\n", camera->z_axis.z);
}

static void			display_sphere_properties(t_object *sphere, int file)
{
	ft_putendl_fd("	sphere:", file);
	dprintf(file, "		x: %f\n", sphere->origin.x);
	dprintf(file, "		y: %f\n", sphere->origin.y);
	dprintf(file, "		z: %f\n", sphere->origin.z);
	dprintf(file, "		rotX: %f\n", sphere->rotX);
	dprintf(file, "		rotY: %f\n", sphere->rotY);
	dprintf(file, "		rotZ: %f\n", sphere->rotZ);
	dprintf(file, "		radius: %f\n", sphere->radius);
	dprintf(file, "		color: %X\n", sphere->color.color);
	dprintf(file, "		ambient: %f\n", sphere->ambient);
	dprintf(file, "		diffuse: %f\n", sphere->ambient);
	dprintf(file, "		specular: %f\n", sphere->specular);
	dprintf(file, "		reflection: %f\n", sphere->reflection);
	dprintf(file, "		refraction: %f\n", sphere->refraction);
}

static void			display_plane_properties(t_object *plane, int file)
{
	ft_putendl_fd("	plane:", file);
	dprintf(file, "		x: %f\n", plane->origin.x);
	dprintf(file, "		y: %f\n", plane->origin.y);
	dprintf(file, "		z: %f\n", plane->origin.z);
	dprintf(file, "		normX: %f\n", plane->normal.x);
	dprintf(file, "		normY: %f\n", plane->normal.y);
	dprintf(file, "		normZ: %f\n", plane->normal.z);
	dprintf(file, "		radius: %f\n", plane->radius);
	dprintf(file, "		color: %X\n", plane->color.color);
	dprintf(file, "		ambient: %f\n", plane->ambient);
	dprintf(file, "		diffuse: %f\n", plane->ambient);
	dprintf(file, "		specular: %f\n", plane->specular);
	dprintf(file, "		reflection: %f\n", plane->reflection);
	dprintf(file, "		refraction: %f\n", plane->refraction);
}

static void			display_light_properties(t_light *light, int file)
{
	ft_putendl_fd("	light:", file);
	dprintf(file, "		x: %f\n", light->origin.x);
	dprintf(file, "		y: %f\n", light->origin.y);
	dprintf(file, "		z: %f\n", light->origin.z);
	dprintf(file, "		intensity: %f\n", light->intensity);
	dprintf(file, "		red: %f\n", light->color.red);
	dprintf(file, "		green: %f\n", light->color.green);
	dprintf(file, "		blue: %f\n", light->color.blue);
}

static void			display_scene_header(int file)
{
	ft_putendl_fd("scene:", file);
	ft_putstr_fd("	render_width: ", file);
	ft_putnbr_fd(env->scene->view_width, file);
	ft_putendl_fd("", file);
	ft_putstr_fd("	render_height: ", file);
	ft_putnbr_fd(env->scene->view_height, file);
	ft_putendl_fd("", file);
}

void				export_scene(int file)
{
	t_object		*object;
	t_light			*light;

	display_scene_header(file);
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

void				cmd_export(char **line)
{
	int				file;

	file = 1;
	if ((ft_strequ(*line, "image")
		|| ft_strequ(*line, "scene"))
		&& line[1])
		file = open(line[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else
		ft_putendl_fd("usage: export [image|scene] <file>", 2);
	if (file > 0)
	{
		if (ft_strequ(*line, "image"))
			export_image(file);
		else if (ft_strequ(*line, "scene"))
			export_scene(file);
		close(file);
	}
}
