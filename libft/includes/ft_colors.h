/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:54:50 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 20:50:29 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# define COLOR_BLEND_OVER		0
# define COLOR_BLEND_ADD		1
# define COLOR_BLEND_SUB		2
# define COLOR_BLEND_MUL		3
# define COLOR_BLEND_DIV		4
# define COLOR_BLEND_HARD_LIGHT	5
# define COLOR_BLEND_SOFT_LIGHT	6

typedef union			u_color
{
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	};
	int					color;
}						t_color;

t_color			fade_color(t_color a, float opacity);
int				blend_colors(int color1, int color2, float coeff, int type);

t_color			color_blend_over(t_color a, t_color b);
t_color			color_blend_add(t_color a, t_color b);
t_color			color_blend_sub(t_color a, t_color b);

#endif
