/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:35:06 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:41:13 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_width(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_NONE)
		env->scene->view_width = (unsigned int)ft_atoi(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: width.", 2);
}
