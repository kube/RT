/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:41:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 21:39:26 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_colors.h>

t_color				color_blend_sub(t_color a, t_color b)
{
	t_color			c;
	int				red;
	int				green;
	int				blue;

	red = (int)a.r * (int)a.a - (int)b.r * (int)b.a;
	green = (int)a.g * (int)a.a - (int)b.g * (int)b.a;
	blue = (int)a.b * (int)a.a - (int)b.b * (int)b.a;
	if ((int)a.a + (int)b.a > 0)
		c.a = ((a.a > b.a) ? a.a : b.a);
	else
		c.a = 0;
	if (red > 0)
		c.r = (unsigned char)(red / 255);
	else
		c.r = 0;
	if (green > 0)
		c.g = (unsigned char)(green / 255);
	else
		c.g = 0;
	if (blue > 0)
		c.b = (unsigned char)(blue / 255);
	else
		c.b = 0;
	return (c);
}
