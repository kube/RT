/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:34:33 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 20:35:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <object.h>
#include <stdlib.h>

void			create_test_objects(t_scene *scene)
{
	scene->objects = NULL;

	add_object(scene, new_object(OBJ_SPHERE));
	scene->objects->origin.x = 10;
	scene->objects->radius = 2;
	scene->objects->color.color = 0xFFFFFFFF;
	scene->objects->ambient = 0.1;
	scene->objects->diffuse = 0.8;
	scene->objects->specular = 0.1;

	add_object(scene, new_object(OBJ_SPHERE));
	scene->objects->origin.x = 9;
	scene->objects->origin.y = -1;
	scene->objects->origin.z = 1.5;
	scene->objects->radius = 1;
	scene->objects->color.color = 0xFFFF0AFF;
	scene->objects->ambient = 0.1;
	scene->objects->diffuse = 0.8;
	scene->objects->specular = 0.4;

	add_object(scene, new_object(OBJ_PLANE));
	scene->objects->origin.z = -1;
	scene->objects->normal.z = 1;
	scene->objects->color.color = 0xFF0904FA;
	scene->objects->ambient = 0.1;
	scene->objects->diffuse = 0.8;
	scene->objects->specular = 0.4;

	add_object(scene, new_object(OBJ_SPHERE));
	scene->objects->origin.x = -10;
	scene->objects->radius = 1.5;
	scene->objects->color.color = 0x000000FF;
	scene->objects->ambient = 0.1;
	scene->objects->diffuse = 0.8;
	scene->objects->specular = 0.4;

	add_object(scene, new_object(OBJ_SPHERE));
	scene->objects->radius = 150;
	scene->objects->color.color = 0xFF2F5FFF;
	scene->objects->ambient = 0.8;
	scene->objects->diffuse = 0.4;
	scene->objects->specular = 0.2;


	scene->lights = (t_light *)malloc(sizeof(t_light));
	scene->lights->type = 0;
	scene->lights->origin.x = 0;
	scene->lights->origin.y = 10;
	scene->lights->origin.z = 5;
	scene->lights->intensity = 1.0;
	scene->lights->color.red = 1.0;
	scene->lights->color.green = 1.0;
	scene->lights->color.blue = 1.0;

	scene->lights->next = NULL;

	scene->lights->next = (t_light *)malloc(sizeof(t_light));
	scene->lights->next->type = 0;
	scene->lights->next->origin.x = 10;
	scene->lights->next->origin.y = -10;
	scene->lights->next->origin.z = 2;
	scene->lights->next->intensity = 1.0;
	scene->lights->next->color.red = 1.0;
	scene->lights->next->color.green = 0.0;
	scene->lights->next->color.blue = 0.0;

	scene->lights->next->next = (t_light *)malloc(sizeof(t_light));
	scene->lights->next->next->type = 0;
	scene->lights->next->next->origin.x = 15;
	scene->lights->next->next->origin.y = -10;
	scene->lights->next->next->origin.z = 10;
	scene->lights->next->next->intensity = 9.0;
	scene->lights->next->next->color.red = 0.0;
	scene->lights->next->next->color.green = 0.0;
	scene->lights->next->next->color.blue = 1.0;
	scene->lights->next->next->next = NULL;
}