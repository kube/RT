/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 19:42:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <unistd.h>
#include <fcntl.h>

void				cmd_export(char **line)
{
	int				file;

	file = 1;
	if ((ft_strequ(*line, "image")
		|| ft_strequ(*line, "scene"))
		&& line[1])
		file = open(line[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else
		ft_putendl_fd("usage: export [image|scene] <file>", 2);
	if (file > 0)
	{
		if (ft_strequ(*line, "image"))
			export_image(file);
		else if (ft_strequ(*line, "scene"))
			export_scene(file);
		close(file);
	}
}
