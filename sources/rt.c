/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:30:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 15:14:06 by cfeijoo          ###   ########.fr       */
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

	i = env->view_width * (unsigned int)a.y + (unsigned int)a.x;
	if (i < env->view_width * env->view_height && (int)a.y >= 0 && (int)a.x >= 0
		&& (unsigned int)a.x < env->view_width)
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

static void				get_fps()
{
	static int			i = 0;
	static float		last_put = 0;
	float				time_ms;

	i++;
	time_ms = ((float)clock() / (float)CLOCKS_PER_SEC);
	if (time_ms - last_put > 1)
	{
		printf("%d FPS\n", i);
		last_put = time_ms;
		i = 0;
	}
}

int					throw_view_plane(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_ray			ray;
	t_point			tmp;

	/*
	** This function will be bettered with vector operations added in LibFt
	*/
	i = 0;
	j = 0;

	env->block_events = 1;

	ray.origin.x = env->camera.origin.x;
	ray.origin.y = env->camera.origin.y;
	ray.origin.z = env->camera.origin.z;

	ray.direction.x = env->camera.x_axis.x;
	ray.direction.y = env->camera.x_axis.y;
	ray.direction.z = env->camera.x_axis.z;

	ray.direction.x += (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.y += (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.z += (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width / 2;

	ray.direction.x += (env->camera.z_axis.x / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.y += (env->camera.z_axis.y / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.z += (env->camera.z_axis.z / VIEWPLANE_PLOT) * env->view_height / 2;


	while (j < env->view_height)
	{
		i = 0;
		while (i < env->view_width)
		{
			// TREAT RAY HERE
			tmp.x = (float)i;
			tmp.y = (float)j;
			
			throw_ray(env, &ray, !env->pressed_keys.shift);

			if (ray.inter_t != INFINITY && !env->pressed_keys.shift)
				pixel_to_image(env, tmp, light_diaphragm(&ray, env->diaphragm));
			else if (ray.inter_t != INFINITY)
				pixel_to_image(env, tmp, ray.closest->color.color);
			else if (!env->pressed_keys.no_clean)
				pixel_to_image(env, tmp, env->background_color);
			// END TREAT RAY
			ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT);
			ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT);
			ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT);
			i++;
		}
		ray.direction.x -= (env->camera.z_axis.x / VIEWPLANE_PLOT);
		ray.direction.y -= (env->camera.z_axis.y / VIEWPLANE_PLOT);
		ray.direction.z -= (env->camera.z_axis.z / VIEWPLANE_PLOT);

		// BACK TO ZERO ON Y-AXIS
		ray.direction.x += (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width;
		ray.direction.y += (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width;
		ray.direction.z += (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width;
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

	env->block_events = 0;

	get_fps();

	return (0);
}

static int			view_loop(t_env *env)
{
	if (!env->block_events && is_one_key_pressed(&env->pressed_keys))
	{
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
	**	Simplify all this stuff
	*/
	ray.origin.x = env->camera.origin.x;
	ray.origin.y = env->camera.origin.y;
	ray.origin.z = env->camera.origin.z;

	ray.direction.x = env->camera.x_axis.x;
	ray.direction.y = env->camera.x_axis.y;
	ray.direction.z = env->camera.x_axis.z;

	ray.direction.x += (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.y += (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.z += (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width / 2;

	ray.direction.x += (env->camera.z_axis.x / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.y += (env->camera.z_axis.y / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.z += (env->camera.z_axis.z / VIEWPLANE_PLOT) * env->view_height / 2;

	/*
	**	Move to good point
	*/
	ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT) * i;
	ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT) * i;
	ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT) * i;
	
	ray.direction.x -= (env->camera.z_axis.x / VIEWPLANE_PLOT) * j;
	ray.direction.y -= (env->camera.z_axis.y / VIEWPLANE_PLOT) * j;
	ray.direction.z -= (env->camera.z_axis.z / VIEWPLANE_PLOT) * j;


	return (ray);
}

static void			create_test_objects(t_env *env)
{
	env->objects = NULL;

	add_object(env, new_object(OBJ_SPHERE));
	env->objects->origin.x = 10;
	env->objects->radius = 2;
	env->objects->color.color = 0xFFFFFFFF;
	env->objects->ambient = 0.1;
	env->objects->diffuse = 0.8;
	env->objects->specular = 0.1;

	add_object(env, new_object(OBJ_SPHERE));
	env->objects->origin.x = 9;
	env->objects->origin.y = -1;
	env->objects->origin.z = 1.5;
	env->objects->radius = 1;
	env->objects->color.color = 0xFFFF0AFF;
	env->objects->ambient = 0.1;
	env->objects->diffuse = 0.8;
	env->objects->specular = 0.4;

	add_object(env, new_object(OBJ_PLANE));
	env->objects->origin.z = -1;
	env->objects->normal.z = 1;
	env->objects->color.color = 0xFF0904FA;
	env->objects->ambient = 0.1;
	env->objects->diffuse = 0.8;
	env->objects->specular = 0.4;

	add_object(env, new_object(OBJ_SPHERE));
	env->objects->origin.x = -10;
	env->objects->radius = 1.5;
	env->objects->color.color = 0x000000FF;
	env->objects->ambient = 0.1;
	env->objects->diffuse = 0.8;
	env->objects->specular = 0.4;

	add_object(env, new_object(OBJ_SPHERE));
	env->objects->radius = 150;
	env->objects->color.color = 0xFF2F5FFF;
	env->objects->ambient = 0.8;
	env->objects->diffuse = 0.4;
	env->objects->specular = 0.2;



	env->lights = (t_light *)malloc(sizeof(t_light));
	env->lights->type = 0;
	env->lights->origin.x = 0;
	env->lights->origin.y = 10;
	env->lights->origin.z = 5;
	env->lights->intensity = 1.0;
	env->lights->color.red = 1.0;
	env->lights->color.green = 1.0;
	env->lights->color.blue = 1.0;

	env->lights->next = NULL;

	env->lights->next = (t_light *)malloc(sizeof(t_light));
	env->lights->next->type = 0;
	env->lights->next->origin.x = 10;
	env->lights->next->origin.y = -10;
	env->lights->next->origin.z = 2;
	env->lights->next->intensity = 1.0;
	env->lights->next->color.red = 1.0;
	env->lights->next->color.green = 0.0;
	env->lights->next->color.blue = 0.0;

	env->lights->next->next = (t_light *)malloc(sizeof(t_light));
	env->lights->next->next->type = 0;
	env->lights->next->next->origin.x = 15;
	env->lights->next->next->origin.y = -10;
	env->lights->next->next->origin.z = 10;
	env->lights->next->next->intensity = 4.0;
	env->lights->next->next->color.red = 0.0;
	env->lights->next->next->color.green = 0.0;
	env->lights->next->next->color.blue = 1.0;
	env->lights->next->next->next = NULL;
}

int					main(int argc, char **argv)
{
	t_env			env;

	if (argc == 2)
	{
		parse_file(argv[1]);
		return (0);
	}
	env.view_width = RENDER_WIDTH;
	env.view_height = RENDER_HEIGHT;
	env.block_events = 0;


	env.selected_object = NULL;
	env.pressed_mouse = 0;

	env.background_color = 0xFF000000;
	env.diaphragm = 1.0;
	env.matters = NULL;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.view_width, env.view_height, "RT");
	env.img = mlx_new_image(env.mlx, env.view_width, env.view_height);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line),
				&(env.endian));

	init_cam(&env.camera, 0, 0, 0);
	init_cam_angle(&env.camera, 0, 0);
	create_test_objects(&env);
	init_pressed_keys(&env.pressed_keys);

	mlx_expose_hook(env.win, throw_view_plane, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env.pressed_keys);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env.pressed_keys);
	mlx_hook(env.win, ButtonPress, ButtonPressMask, buttonpress_hook, &env);
	mlx_hook(env.win, ButtonRelease, ButtonReleaseMask, buttonrelease_hook, &env);
	mlx_hook(env.win, MotionNotify, PointerMotionMask, motionnotify_hook, &env);
	mlx_loop_hook(env.mlx, view_loop, &env);
	mlx_loop(env.mlx);

	return (0);
}
