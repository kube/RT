/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:01:22 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/11 23:58:48 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <ft_math.h>
# include <ft_colors.h>

# define OBJ_SPHERE		0
# define OBJ_PLANE		1
# define OBJ_CYLINDER	2
# define OBJ_CONE		3

typedef struct				s_object
{
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

typedef union				u_light_color
{
	struct
	{
		float				red;
		float				green;
		float				blue;
	};
	struct
	{
		float				r;
		float				g;
		float				b;
	};
}							t_light_color;

typedef struct				s_light
{
	int						type;
	t_point					origin;
	float					intensity;

	t_vector				direction;
	float					aperture;
	t_light_color			color;
	struct s_light			*next;
}							t_light;

#endif
