/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_recursivity.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:46:25 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:48:44 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_recursivity(t_parser *parser, char **line)
{
	int				rec;

	if (parser->last_type == LAST_NONE)
	{
		rec = ft_atoi(line[0]);
		if (rec >= 0 && rec <= 1000)
			env->scene->recursivity = rec;
	}
	else
		ft_putendl_fd("ERROR! Orphan Property: recursivity.", 2);
}
