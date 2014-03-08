/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/08 12:54:50 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <camera.h>
# include <keyboard.h>
# include <object.h>
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

	t_camera				camera;
	unsigned int			view_width;
	unsigned int			view_height;
	t_object				*objects;
	t_pressedkeys			pressed_keys;

	int						block_events;
}							t_env;

void	init_pressed_keys(t_pressedkeys *keys);
int		keypress_hook(int keycode, t_pressedkeys *keys);
void	check_pressed_keys(t_env *env, t_pressedkeys *keys);
int		keyrelease_hook(int keycode, t_pressedkeys *keys);

#endif
