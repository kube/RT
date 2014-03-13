/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 03:42:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <camera.h>
# include <keyboard.h>
# include <object.h>
# include <matter.h>

# define VIEWPLANE_PLOT 1000

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	int						bpp;
	int						size_line;
	int						endian;
	int						*data;

	float					diaphragm;

	int						background_color;
	t_camera				camera;
	unsigned int			view_width;
	unsigned int			view_height;
	t_matter				*matters;
	t_object				*objects;
	t_light					*lights;
	t_pressedkeys			pressed_keys;

	int						pressed_mouse;
	int						last_mouse_x;
	int						last_mouse_y;

	t_object				*selected_object;

	int						block_events;
}							t_env;

int			throw_view_plane(t_env *env);

void		init_pressed_keys(t_pressedkeys *keys);
int			keypress_hook(int keycode, t_pressedkeys *keys);
void		check_pressed_keys(t_env *env, t_pressedkeys *keys);
int			keyrelease_hook(int keycode, t_pressedkeys *keys);

t_matter	*get_matter(t_env *env, char *name);
void		add_matter(t_env *env, t_matter *matter);
t_matter	*new_matter(char *name);

void		load_matter_object(t_object *object, t_matter *matter);
void		add_object(t_env *env, t_object *object);
t_object	*new_object(int type);
void		remove_object(t_env *env, t_object *object);

#endif
