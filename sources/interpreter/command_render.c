/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 00:15:42 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

void				cmd_render(char **line)
{
	(void)line;
	env->fast_mode = 0;
	env->last_scene_change = clock();
	env->block_events = 1;
}
