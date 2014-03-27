/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:42:37 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 21:21:28 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_input.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <parser.h>
#include <fcntl.h>
#include <stdlib.h>



static int	is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

static int	count_indentation(char *line, int line_number)
{
	int		i;

	i = 0;
	while (is_space(line[i]))
	{
		if (line[i] != '\t')
		{
			ft_putstr_fd("Line ", 2);
			ft_putnbr_fd(line_number, 2);
			ft_putendl_fd(":\tERROR! Bad Indentation.", 2);
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

static void				check_command(int indent_level, t_parser *parser,
										char **command_line, int line)
{
	t_parser_command	*commands;

	commands = parser->commands;
	while (commands)
	{
		if (indent_level == commands->indent_level
			&& ft_strequ(commands->token, *command_line))
		{
			commands->callback(parser, command_line + 1);
			return ;
		}
		commands = commands->next;
	}
	ft_putstr_fd("Line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(":\tERROR! Unrecognized parser command : ", 2);
	ft_putendl_fd(command_line[0], 2);
}

void				parse_line(t_parser *parser, int indent_level, char *line,
								int line_number)
{
	char			**splited;

	line = line + indent_level;
	splited = ft_strsplit(line, ':');
	if (*splited)
	{
		check_command(indent_level, parser, splited, line_number);
		free(splited);
	}
}

static void		parse_scene(int file)
{
	char		*line;
	t_parser	parser;
	int			line_number;

	line_number = 0;
	init_scene_parser(&parser);
	parser.last_type = LAST_NONE;
	while (get_next_line(file, &line)*1)
	{
		remove_comments(line);
		if (!is_empty_line(line))
			parse_line(&parser, count_indentation(line, line_number),
						line, line_number);
		line_number++;
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
