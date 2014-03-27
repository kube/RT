/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_intensity.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:45:59 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:23:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_intensity(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		env->scene->lights->intensity = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: intensity.", 2);
}
