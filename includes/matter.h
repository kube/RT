/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:17:51 by kube              #+#    #+#             */
/*   Updated: 2014/03/19 23:03:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATTER_H
# define MATTER_H
# include <ft_colors.h>

typedef struct				s_matter
{
	char					*name;
	t_color					color;
	float					opacity;
	float					ambient;
	float					diffuse;
	float					specular;
	float					reflection;
	float					refraction;
	float					refract_index;
	struct s_matter			*next;
}							t_matter;

t_matter	*get_matter(char *name);
void		add_matter(t_matter *matter);
t_matter	*new_matter(char *name);
void		load_matter_to_object(t_object *object, t_matter *matter);

#endif
