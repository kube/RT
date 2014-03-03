#ifndef RAY_H
# define RAY_H
# include <ft_colors.h>

typedef struct						s_ray
{
	t_point							origin;
	t_vector						direction;
	unsigned int					recursivity;
	float							intensity;
	t_color							color;
}									t_ray;

#endif
