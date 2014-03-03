/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 17:58:11 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <camera.h>

# define VIEWPLANE_PLOT 1000

/*
**	Environment
*/

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

	t_object				**objects;
}							t_env;

#endif
