/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:53:32 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 16:03:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ft_memory.h>

int			keyrelease_hook(int keycode, t_pressedkeys *keys)
{
	if (keycode == 65363)
		keys->right = 0;
	else if (keycode == 65361)
		keys->left = 0;
	else if (keycode == 65362)
		keys->up = 0;
	else if (keycode == 65364)
		keys->down = 0;
	else if (keycode == 65365)
		keys->p_up = 0;
	else if (keycode == 65366)
		keys->p_down = 0;
	else if (keycode == 65451)
		keys->num_plus = 0;
	else if (keycode == 65453)
		keys->num_minus = 0;
	else if (keycode == 119)
		keys->w = 0;
	else if (keycode == 97)
		keys->a = 0;
	else if (keycode == 115)
		keys->s = 0;
	else if (keycode == 100)
		keys->d = 0;
	else if (keycode == 65535)
		keys->del = 0;
	else if (keycode == 32)
		keys->space = 0;
	else if (keycode == 65507)
		keys->ctrl = 0;
	else if (keycode == 65289)
		keys->tab = 0;
	else if (keycode == 65406 || keycode == 65513)
		keys->alt = 0;
	return (0);
}
