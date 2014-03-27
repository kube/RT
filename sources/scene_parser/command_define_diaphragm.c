/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_diaphragm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:49:44 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 21:03:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <stdlib.h>

void				cmd_define_diaphragm(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_NONE)
		env->scene->diaphragm = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: diaphragm.", 2);
}
