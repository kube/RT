/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 21:50:23 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <camera.h>
# include <keyboard.h>
# include <object.h>
# include <light.h>
# include <matter.h>
# include <interpreter.h>

# include <time.h>
# include <pthread.h>

# define VIEWPLANE_PLOT 1000
# define RENDER_SPLIT	2

typedef struct				s_scene
{
	t_camera				camera;
	t_camera				render_cam;
	unsigned int			view_width;
	unsigned int			view_height;
	float					diaphragm;
	int						background_color;
	t_matter				*matters;
	t_object				*objects;
	t_light					*lights;
}							t_scene;

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
void		render_to_image();

t_matter	*get_matter(char *name);
void		add_matter(t_matter *matter);
t_matter	*new_matter(char *name);

void		load_matter_object(t_object *object, t_matter *matter);
t_object	*new_object(int type);
void		add_object(t_scene *scene, t_object *object);
void		duplicate_object(t_object *object);
void		remove_object(t_scene *scene, t_object *object);
void		remove_light(t_scene *scene, t_light *light);

void		init_pressed_keys(t_pressedkeys *keys);
int			keypress_hook(int keycode, t_pressedkeys *keys);
void		check_pressed_keys(t_pressedkeys *keys);
int			keyrelease_hook(int keycode, t_pressedkeys *keys);

int			create_interpreter_thread();

void		light_to_render(int x, int y,
							t_light_color *light);
void		clean_light_on_render(int x, int y);
void		ask_image_refresh();

#endif
