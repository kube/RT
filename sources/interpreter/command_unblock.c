/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unblock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 00:25:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

void				cmd_unblock(char **line)
{
	(void)line;
	env->block_events = 0;
}
