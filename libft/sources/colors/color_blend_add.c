/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:42:18 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 21:39:19 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_colors.h>

t_color				color_blend_add(t_color a, t_color b)
{
	t_color			c;
	int				red;
	int				green;
	int				blue;

	red = (int)a.r * (int)a.a + (int)b.r * (int)b.a;
	green = (int)a.g * (int)a.a + (int)b.g * (int)b.a;
	blue = (int)a.b * (int)a.a + (int)b.b * (int)b.a;
	if ((int)a.a + (int)b.a < 255)
		c.a = (unsigned char)((int)a.a + (int)b.a);
	else
		c.a = 255;
	if (red < 255 * 255)
		c.r = (unsigned char)(red / 255);
	else
		c.r = 255;
	if (green < 255 * 255)
		c.g = (unsigned char)(green / 255);
	else
		c.g = 255;
	if (blue < 255 * 255)
		c.b = (unsigned char)(blue / 255);
	else
		c.b = 255;
	return (c);
}
