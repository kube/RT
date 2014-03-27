/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 23:03:03 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 17:09:54 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct				s_scene
{
	struct s_camera			camera;
	struct s_camera			render_cam;
	unsigned int			view_width;
	unsigned int			view_height;
	struct s_object			*objects;
	struct s_light			*lights;
	float					diaphragm;
	int						recursivity;
	unsigned int			antialias;
}							t_scene;

#endif
