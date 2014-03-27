/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:42:37 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 02:47:05 by cfeijoo          ###   ########.fr       */
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

static int	count_indentation(char *line)
{
	int		i;

	i = 0;
	while (is_space(line[i]))
	{
		if (line[i] != '\t')
		{
			ft_putendl_fd("ERROR: Bad Indentation!", 2);
			exit(1);
		}
		else
			i++;
	}
	return (i);
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


static void		init_scene_parser()
{
	// parser_add_command(&interpreter->commands, "list", cmd_list);
	// parser_add_command(&interpreter->commands, "remove", cmd_remove);
	// parser_add_command(&interpreter->commands, "add", cmd_add);
	// parser_add_command(&interpreter->commands, "export", cmd_export);
	// parser_add_command(&interpreter->commands, "antialias", cmd_antialias);
	// parser_add_command(&interpreter->commands, "render", cmd_render);
	// parser_add_command(&interpreter->commands, "edit_mode", cmd_editmode);
	// parser_add_command(&interpreter->commands, "recursivity",
	// 						cmd_recursivity);
	// parser_add_command(&interpreter->commands, "unblock", cmd_unblock);	
}

static void		parse_scene(int file)
{
	char		*line;
	t_parser	parser;

	parser.last_type = 0;
	while (get_next_line(file, &line)*1)
	{
		remove_comments(line);
		if (!is_empty_line(line))
		{
			ft_putendl(line);
			(void)count_indentation;
			// parse_line(parser, line, count_indentation(line));
		}
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
