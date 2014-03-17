/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:30:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 20:04:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <ft_math.h>
#include <ft_colors.h>
#include <ft_convert.h>
#include <ft_memory.h>
#include <math.h>
#include <mlx.h>
#include <X.h>
#include <rt.h>
#include <ray.h>
#include <parser.h>
#include <stdlib.h>
#include <mouse.h>
#include <interpreter.h>

#include <pthread.h>


#include <stdio.h>
#include <time.h>

/*
** This is just for development, render dimensions will be parsed in File
*/
#define RENDER_WIDTH			1100
#define RENDER_HEIGHT			670

static void			rendering_to_image(t_env *env)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < env->scene->view_height)
	{
		x = 0;
		while (x < env->scene->view_width)
		{
			pixel_to_image(env, x, y,
				light_diaphragm(&env->rendering[y * env->scene->view_width + x],
					env->scene->diaphragm));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

static int			view_loop(t_env *env)
{

	if (is_one_key_pressed(&env->pressed_keys))
		check_pressed_keys(env, &env->pressed_keys);
	if (!env->running_threads && !env->block_render && env->refresh_image)
		update_image(env);
	if (!env->running_threads)
	{
		if (!env->pressed_keys.shift && env->refresh_image)
			rendering_to_image(env);
		else
			mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		env->block_render = 0;
	}
	return (0);
}

t_ray				get_ray_from_point(t_env *env, int i, int j)
{
	t_ray			ray;

	ray.origin.x = env->scene->camera.origin.x;
	ray.origin.y = env->scene->camera.origin.y;
	ray.origin.z = env->scene->camera.origin.z;
	ray.direction.x = env->scene->camera.x_axis.x;
	ray.direction.y = env->scene->camera.x_axis.y;
	ray.direction.z = env->scene->camera.x_axis.z;
	i -= env->scene->view_width / 2;
	j -= env->scene->view_height / 2;
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
	scene->lights->next->next->intensity = 9.0;
	scene->lights->next->next->color.red = 0.0;
	scene->lights->next->next->color.green = 0.0;
	scene->lights->next->next->color.blue = 1.0;
	scene->lights->next->next->next = NULL;
}


int					update_image(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_thread_input	*input;

	j = 0;
	while (j < RENDER_SPLIT)
	{
		i = 0;
		while (i < RENDER_SPLIT)
		{
			input = (t_thread_input*)malloc(sizeof(*input));
			input->env = env;
			input->x1 = i * (env->scene->view_width / RENDER_SPLIT);
			input->y1 = j * (env->scene->view_height / RENDER_SPLIT);
			input->x2 = env->scene->view_width - (RENDER_SPLIT - 1 - i)
						* (env->scene->view_width / RENDER_SPLIT);
			input->y2 = env->scene->view_width - (RENDER_SPLIT - 1 - j)
						* (env->scene->view_height / RENDER_SPLIT);
			input->thread_number = j * RENDER_SPLIT + i;
			create_render_thread(env, input);
			i++;
		}
		j++;
	}
	return (0);
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

	env.selected_object = NULL;
	env.pressed_mouse = 0;
	env.running_threads = 0;
	env.block_render = 0;
	env.refresh_image = 1;

	env.scene->background_color = 0xFF000000;
	env.scene->diaphragm = 1.0;
	env.scene->matters = NULL;

	env.interpreter_thread = 0;

	env.render_threads = (pthread_t*)ft_memalloc(RENDER_SPLIT * RENDER_SPLIT
						* sizeof(pthread_t));
	env.rendering = (t_light_color*)ft_memalloc(env.scene->view_width
					* env.scene->view_height * sizeof(t_light_color));

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.scene->view_width,
				env.scene->view_height, "RT");
	env.img = mlx_new_image(env.mlx, env.scene->view_width,
				env.scene->view_height);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp),
				&(env.size_line), &(env.endian));

	init_cam(&env.scene->camera, 0, 0, 0);
	init_cam_angle(&env.scene->camera, 0, 0);
	create_test_objects(env.scene);
	init_pressed_keys(&env.pressed_keys);

	create_interpreter_thread(&env);

	mlx_expose_hook(env.win, view_loop, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
	mlx_hook(env.win, ButtonPress, ButtonPressMask, mousepress_ev, &env);
	mlx_hook(env.win, ButtonRelease, ButtonReleaseMask, mouserelease_ev, &env);
	mlx_hook(env.win, MotionNotify, PointerMotionMask, motionnotify_ev, &env);
	mlx_loop_hook(env.mlx, view_loop, &env);
	mlx_loop(env.mlx);
	return (0);
}
