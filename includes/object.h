/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:01:22 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/25 16:04:54 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include <scene.h>
# include <ft_math.h>
# include <ft_colors.h>

# define OBJ_SPHERE		0
# define OBJ_PLANE		1
# define OBJ_CYLINDER	2
# define OBJ_CONE		3

typedef struct				s_object
{
	char					*name;
	int						type;
	t_point					origin;
	union
	{
		struct
		{
			float			rotX;
			float			rotY;
			float			rotZ;
		};
		t_vector			normal;
	};
	t_color					color;
	float					opacity;
	float					ambient;
	float					diffuse;
	float					specular;
	float					reflection;
	float					refraction;
	float					refract_index;
	union
	{
		float				radius;
		float				aperture;
	};
	struct s_object			*next;
}							t_object;

t_object	*new_object(int type);
void		add_object(t_scene *scene, t_object *object);
void		duplicate_object(t_object *object);
void		remove_object(t_scene *scene, t_object *object);

#endif
