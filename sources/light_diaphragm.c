/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_diaphragm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:03:19 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 20:03:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>

int					light_diaphragm(t_light_color *light, float diaphragm)
{
	t_color 		color;

	color.red = (unsigned char)(fmin((light->red / diaphragm), 1.0) * 255);
	color.blue = (unsigned char)(fmin((light->blue / diaphragm), 1.0) * 255);
	color.green = (unsigned char)(fmin((light->green / diaphragm), 1.0) * 255);
	return (color.color);
}
