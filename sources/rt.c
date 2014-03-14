/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:30:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 17:16:51 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <ft_math.h>
#include <ft_colors.h>
#include <ft_convert.h>
#include <math.h>
#include <mlx.h>
#include <X.h>
#include <rt.h>
#include <ray.h>
#include <parser.h>
#include <stdlib.h>
#include <mouse.h>

#include <stdio.h>
#include <time.h>

/*
** This is just for development, render dimensions will be parsed in File
*/
#define RENDER_WIDTH	1100
#define RENDER_HEIGHT	670


static void			pixel_to_image(t_env *env, t_point a, int color)
{
	unsigned int	i;

	i = env->scene->view_width * (unsigned int)a.y + (unsigned int)a.x;
	if (i < env->scene->view_width * env->scene->view_height && (int)a.y >= 0 && (int)a.x >= 0
		&& (unsigned int)a.x < env->scene->view_width)
		env->data[i] = color;
}

static float		min_float(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

static int			light_diaphragm(t_ray *ray, float diaphragm)
{
	t_color 		color;

	color.red = (unsigned char)(min_float((ray->color.red / diaphragm), 1.0) * 255);
	color.blue = (unsigned char)(min_float((ray->color.blue / diaphragm), 1.0) * 255);
	color.green = (unsigned char)(min_float((ray->color.green / diaphragm), 1.0) * 255);
	return (color.color);
}

int					throw_view_plane(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_ray			ray;
	t_point			tmp;

	float			time_ms;
	
	time_ms = ((float)clock() / (float)CLOCKS_PER_SEC);

	/*
	** This function will be bettered with vector operations added in LibFt
	*/
	i = 0;
	j = 0;

	env->block_events = 1;

	ray.origin.x = env->scene->camera.origin.x;
	ray.origin.y = env->scene->camera.origin.y;
	ray.origin.z = env->scene->camera.origin.z;

	ray.direction.x = env->scene->camera.x_axis.x;
	ray.direction.y = env->scene->camera.x_axis.y;
	ray.direction.z = env->scene->camera.x_axis.z;

	ray.direction.x += (env->scene->camera.y_axis.x / VIEWPLANE_PLOT) * env->scene->view_width / 2;
	ray.direction.y += (env->scene->camera.y_axis.y / VIEWPLANE_PLOT) * env->scene->view_width / 2;
	ray.direction.z += (env->scene->camera.y_axis.z / VIEWPLANE_PLOT) * env->scene->view_width / 2;

	ray.direction.x += (env->scene->camera.z_axis.x / VIEWPLANE_PLOT) * env->scene->view_height / 2;
	ray.direction.y += (env->scene->camera.z_axis.y / VIEWPLANE_PLOT) * env->scene->view_height / 2;
	ray.direction.z += (env->scene->camera.z_axis.z / VIEWPLANE_PLOT) * env->scene->view_height / 2;

	while (j < env->scene->view_height)
	{
		i = 0;
		while (i < env->scene->view_width)
		{
			// TREAT RAY HERE
			tmp.x = (float)i;
			tmp.y = (float)j;
			
			throw_ray(env, &ray, !env->pressed_keys.shift);

			if (ray.inter_t != INFINITY && !env->pressed_keys.shift)
				pixel_to_image(env, tmp, light_diaphragm(&ray, env->scene->diaphragm));
			else if (ray.inter_t != INFINITY)
				pixel_to_image(env, tmp, ray.closest->color.color);
			else
				pixel_to_image(env, tmp, env->scene->background_color);
			// END TREAT RAY
			ray.direction.x -= (env->scene->camera.y_axis.x / VIEWPLANE_PLOT);
			ray.direction.y -= (env->scene->camera.y_axis.y / VIEWPLANE_PLOT);
			ray.direction.z -= (env->scene->camera.y_axis.z / VIEWPLANE_PLOT);
			i++;
		}
		ray.direction.x -= (env->scene->camera.z_axis.x / VIEWPLANE_PLOT);
		ray.direction.y -= (env->scene->camera.z_axis.y / VIEWPLANE_PLOT);
		ray.direction.z -= (env->scene->camera.z_axis.z / VIEWPLANE_PLOT);

		// BACK TO ZERO ON Y-AXIS
		ray.direction.x += (env->scene->camera.y_axis.x / VIEWPLANE_PLOT) * env->scene->view_width;
		ray.direction.y += (env->scene->camera.y_axis.y / VIEWPLANE_PLOT) * env->scene->view_width;
		ray.direction.z += (env->scene->camera.y_axis.z / VIEWPLANE_PLOT) * env->scene->view_width;
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

	env->block_events = 0;

	time_ms = ((float)clock() / (float)CLOCKS_PER_SEC) - time_ms;
	printf("Render : %f ms\n", time_ms);

	return (0);
}

static int			view_loop(t_env *env)
{
	// printf("view_loop_A\n");
	if (!env->block_events && is_one_key_pressed(&env->pressed_keys))
	{
		printf("view_loop_B\n");
		check_pressed_keys(env, &env->pressed_keys);
		env->block_events = 1;
		throw_view_plane(env);
		env->block_events = 0;
	}
	return (0);
}

t_ray				get_ray_from_point(t_env *env, int i, int j)
{
	t_ray			ray;

	/*
	**	Gotta Simplify all this stuff !
	*/
	ray.origin.x = env->scene->camera.origin.x;
	ray.origin.y = env->scene->camera.origin.y;
	ray.origin.z = env->scene->camera.origin.z;

	ray.direction.x = env->scene->camera.x_axis.x;
	ray.direction.y = env->scene->camera.x_axis.y;
	ray.direction.z = env->scene->camera.x_axis.z;

	ray.direction.x += (env->scene->camera.y_axis.x / VIEWPLANE_PLOT) * env->scene->view_width / 2;
	ray.direction.y += (env->scene->camera.y_axis.y / VIEWPLANE_PLOT) * env->scene->view_width / 2;
	ray.direction.z += (env->scene->camera.y_axis.z / VIEWPLANE_PLOT) * env->scene->view_width / 2;

	ray.direction.x += (env->scene->camera.z_axis.x / VIEWPLANE_PLOT) * env->scene->view_height / 2;
	ray.direction.y += (env->scene->camera.z_axis.y / VIEWPLANE_PLOT) * env->scene->view_height / 2;
	ray.direction.z += (env->scene->camera.z_axis.z / VIEWPLANE_PLOT) * env->scene->view_height / 2;

	/*
	**	Move to good point
	*/
	ray.direction.x -= (env->scene->camera.y_axis.x / VIEWPLANE_PLOT) * i;
	ray.direction.y -= (env->scene->camera.y_axis.y / VIEWPLANE_PLOT) * i;
	ray.direction.z -= (env->scene->camera.y_axis.z / VIEWPLANE_PLOT) * i;
	
	ray.direction.x -= (env->scene->camera.z_axis.x / VIEWPLANE_PLOT) * j;
	ray.direction.y -= (env->scene->camera.z_axis.y / VIEWPLANE_PLOT) * j;
	ray.direction.z -= (env->scene->camera.z_axis.z / VIEWPLANE_PLOT) * j;


	return (ray);
}

static void			create_test_objects(t_scene *scene)
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
	scene->lights->next->next->intensity = 4.0;
	scene->lights->next->next->color.red = 0.0;
	scene->lights->next->next->color.green = 0.0;
	scene->lights->next->next->color.blue = 1.0;
	scene->lights->next->next->next = NULL;
}

int					main(int argc, char **argv)
{
	t_env			env;

	if (argc == 2)
	{
		parse_file(argv[1]);
		return (0);
	}
	env.scene = (t_scene*)malloc(sizeof(t_scene));

	env.scene->view_width = RENDER_WIDTH;
	env.scene->view_height = RENDER_HEIGHT;
	env.block_events = 0;


	env.selected_object = NULL;
	env.pressed_mouse = 0;

	env.scene->background_color = 0xFF000000;
	env.scene->diaphragm = 1.0;
	env.scene->matters = NULL;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.scene->view_width, env.scene->view_height, "RT");
	env.img = mlx_new_image(env.mlx, env.scene->view_width, env.scene->view_height);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line),
				&(env.endian));

	init_cam(&env.scene->camera, 0, 0, 0);
	init_cam_angle(&env.scene->camera, 0, 0);
	create_test_objects(env.scene);
	init_pressed_keys(&env.pressed_keys);


	mlx_expose_hook(env.win, throw_view_plane, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
	mlx_hook(env.win, ButtonPress, ButtonPressMask, buttonpress_hook, &env);
	mlx_hook(env.win, ButtonRelease, ButtonReleaseMask, buttonrelease_hook, &env);
	mlx_hook(env.win, MotionNotify, PointerMotionMask, motionnotify_hook, &env);
	mlx_loop_hook(env.mlx, view_loop, &env);
	mlx_loop(env.mlx);

	return (0);
}
