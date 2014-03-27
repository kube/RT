/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 15:48:42 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <camera.h>
# include <scene.h>
# include <object.h>
# include <light.h>
# include <interpreter.h>
# include <keyboard.h>
# include <time.h>
# include <pthread.h>

# define DEFAULT_VIEW_WIDTH		1300
# define DEFAULT_VIEW_HEIGHT	900
# define VIEWPLANE_PLOT 		1000
# define RENDER_SPLIT			2

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	int						bpp;
	int						size_line;
	int						endian;
	int						*data;

	t_scene					*scene;
	t_light_color			*rendering;
	pthread_t				*render_threads;
	int						running_threads;

	clock_t					last_image_refresh;
	clock_t					last_light_refresh;
	clock_t					last_scene_change;
	int						block_events;
	int						fast_mode;

	t_interpreter			interpreter;
	pthread_t				interpreter_thread;


	t_pressedkeys			pressed_keys;
	t_object				*selected_object;
	int						pressed_mouse;
	int						mouse_x;
	int						mouse_y;
}							t_env;

typedef struct				s_thread_input
{
	unsigned int			x1;
	unsigned int			y1;
	unsigned int			x2;
	unsigned int			y2;
	int						thread_number;
}							t_thread_input;

t_env		*env;

int			update_image();
int			create_render_thread(t_thread_input *input);
void		pixel_to_image(int x, int y, int color);
int			light_diaphragm(t_light_color *light, float diaphragm);
void		light_to_render(int x, int y,
							t_light_color *light);
void		clean_light_on_render(int x, int y);
void		render_to_image();

#endif
