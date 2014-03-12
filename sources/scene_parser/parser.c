/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:42:37 by kube              #+#    #+#             */
/*   Updated: 2014/03/12 02:41:25 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_input.h>
#include <ft_print.h>
#include <parser.h>
#include <fcntl.h>
#include <stdlib.h>

static int	is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

static char	*remove_comments(char *line)
{
	char	*current;

	current = line;
	while (*current)
	{
		if (*current == COMMENT_START_CHAR)
		{
			*current = 0;
			return (line);
		}
		current++;
	}
	return (line);
}

static int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!is_space(*line))
			return (0);
		line++;
	}
	return (1);
}

static void	parse_scene(int file)
{
	char	*line;

	while (get_next_line(file, &line)*1)
	{
		remove_comments(line);
		if (!is_empty_line(line))
			ft_putendl(line);
		free(line);
	}
}

void		parse_file(char *file_name)
{
	int		file;

	file = open(file_name, O_RDONLY);
	if (file > -1)
		parse_scene(file);
	else
	{
		ft_putendl_fd("Failed opening file.", 2);
		exit(1);
	}
}
