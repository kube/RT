/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:30:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 17:17:35 by cfeijoo          ###   ########.fr       */
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

/*
** This is just for development, render dimensions will be parsed in File
*/
#define RENDER_WIDTH 1024
#define RENDER_HEIGHT 768


static void			pixel_to_image(t_env *env, t_point a, int color)
{
	unsigned int	i;

	i = env->view_width * (unsigned int)a.y + (unsigned int)a.x;
	if (i < env->view_width * env->view_height && (int)a.y >= 0 && (int)a.x >= 0
		&& (unsigned int)a.x < env->view_width)
		env->data[i] = color;
}

static void			trace_color(t_env *env, unsigned int i, unsigned int j,
								t_ray *ray)
{
	float			length;
	t_point			a;

	a.x = i;
	a.y = j;
	length = sqrt(ray->direction.x * ray->direction.x + ray->direction.y
		* ray->direction.y + ray->direction.z * ray->direction.z) - 1;
	pixel_to_image(env, a, blend_colors(0xFFFFFFFF, 0xFFFE25ED, length, COLOR_BLEND_OVER));
}

static int			throw_view_plane(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_ray			ray;

	/*
	** This function will be bettered with vector operations added in LibFt
	*/

	i = 0;
	j = 0;
	ray.origin.x = env->camera.origin.x;
	ray.origin.y = env->camera.origin.y;
	ray.origin.y = env->camera.origin.z;

	ray.direction.x = env->camera.x_axis.x;
	ray.direction.y = env->camera.x_axis.y;
	ray.direction.z = env->camera.x_axis.z;

	ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width / 2;

	ray.direction.x -= (env->camera.z_axis.x / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.y -= (env->camera.z_axis.y / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.z -= (env->camera.z_axis.z / VIEWPLANE_PLOT) * env->view_height / 2;

	while (j < env->view_height)
	{
		i = 0;
		while (i < env->view_width)
		{
			// TREAT RAY HERE
			// throw_ray(env, i, j, &ray);
			trace_color(env, i, j, &ray);

			// END TREAT RAY
			ray.direction.x += (env->camera.y_axis.x / VIEWPLANE_PLOT);
			ray.direction.y += (env->camera.y_axis.y / VIEWPLANE_PLOT);
			ray.direction.z += (env->camera.y_axis.z / VIEWPLANE_PLOT);
			i++;
		}
		ray.direction.x += (env->camera.z_axis.x / VIEWPLANE_PLOT);
		ray.direction.y += (env->camera.z_axis.y / VIEWPLANE_PLOT);
		ray.direction.z += (env->camera.z_axis.z / VIEWPLANE_PLOT);

		// BACK TO ZERO ON Y-AXIS
		ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width;
		ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width;
		ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width;
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

static int			view_loop(t_env *env)
{
	check_pressed_keys(env, &env->pressed_keys);
	throw_view_plane(env);
	return (0);
}

int					main(void)
{
	t_env			env;

	env.view_width = RENDER_WIDTH;
	env.view_height = RENDER_HEIGHT;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.view_width, env.view_height, "RT");
	env.img = mlx_new_image(env.mlx, env.view_width, env.view_height);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line),
				&(env.endian));

	init_cam(&env.camera, 0, 0, 0);
	init_cam_angle(&env.camera, 0, 2 * M_PI);
	init_pressed_keys(&env.pressed_keys);

	mlx_expose_hook(env.win, view_loop, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env.pressed_keys);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env.pressed_keys);
	mlx_loop_hook(env.mlx, view_loop, &env);
	mlx_loop(env.mlx);

	return (0);
}
