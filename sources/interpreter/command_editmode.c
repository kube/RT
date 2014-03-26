/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_editmode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 00:16:33 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

void				cmd_editmode(char **line)
{
	(void)line;
	env->fast_mode = 1;
	env->last_scene_change = clock();
	env->block_events = 0;
}
