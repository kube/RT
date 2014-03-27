/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:41:37 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:42:12 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_height(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_NONE)
		env->scene->view_height = (unsigned int)ft_atoi(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: height.", 2);
}
