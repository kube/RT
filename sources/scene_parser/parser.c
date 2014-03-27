/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:42:37 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 14:08:56 by cfeijoo          ###   ########.fr       */
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

static void			check_command(int indent_level, t_parser_command *commands,
									char **command_line)
{
	while (commands)
	{
		if (indent_level == commands->indent_level
			&& ft_strequ(commands->token, *command_line))
		{
			commands->callback(command_line + 1);
			return ;
		}
		commands = commands->next;
	}
	ft_putendl_fd("ERROR! Unrecognized parser command.", 2);
}

static void			parser_add_command(t_parser_command **commands, int indent_level,
										char *token, void (*callback)(char**))
{
	t_parser_command		*new_command;

	new_command = (t_parser_command*)malloc(sizeof(t_parser_command));
	new_command->token = ft_strdup(token);
	new_command->indent_level = indent_level;
	new_command->callback = callback;
	new_command->next = *commands;
	*commands = new_command;
}


// ADD COMMANDS HERE
static void		init_scene_parser(t_parser *parser)
{
	parser->commands = NULL;
	parser_add_command(&parser->commands, 0, "sphere", NULL);
	// parser_add_command(&parser->commands, 1, "radius", cmd_define_radius);
}



void				parse_line(t_parser *parser, int indent_level, char *line)
{
	char			**splited;

	splited = ft_strsplit(line, ':');
	if (*splited)
	{
		check_command(indent_level, parser->commands, splited);
		// free(splited);
		// free(line);
	}
}



static void		parse_scene(int file)
{
	char		*line;
	t_parser	parser;

	init_scene_parser(&parser);
	parser.last_type = 0;
	while (get_next_line(file, &line)*1)
	{
		remove_comments(line);
		if (!is_empty_line(line))
		{
			ft_putendl(line);
			// (void)count_indentation;
			parse_line(&parser, count_indentation(line), line);
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
