/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_intensity.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:45:59 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:51:32 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_intensity(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		env->scene->lights->intensity = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: intensity.", 2);
}
