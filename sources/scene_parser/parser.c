/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:42:37 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 17:44:29 by acollin          ###   ########.fr       */
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

static void			parser_add_command(t_parser_command **commands,
										int indent_level, char *token,
										void (*callback)(t_parser*, char**))
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
	parser_add_command(&parser->commands, 0, "light", cmd_add_light);
	parser_add_command(&parser->commands, 0, "plane", cmd_add_plane);
	parser_add_command(&parser->commands, 0, "cone", cmd_add_cone);
	parser_add_command(&parser->commands, 0, "sphere", cmd_add_sphere);
	parser_add_command(&parser->commands, 0, "cylinder", cmd_add_cylinder);

	parser_add_command(&parser->commands, 1, "x", cmd_define_x);
	parser_add_command(&parser->commands, 1, "y", cmd_define_y);
	parser_add_command(&parser->commands, 1, "z", cmd_define_z);

	parser_add_command(&parser->commands, 1, "rotx", cmd_define_rotx);
	parser_add_command(&parser->commands, 1, "roty", cmd_define_roty);
	parser_add_command(&parser->commands, 1, "rotz", cmd_define_rotz);

	parser_add_command(&parser->commands, 1, "normx", cmd_define_normx);
	parser_add_command(&parser->commands, 1, "normy", cmd_define_normy);
	parser_add_command(&parser->commands, 1, "normz", cmd_define_normz);

	parser_add_command(&parser->commands, 1, "red", cmd_define_red);
	parser_add_command(&parser->commands, 1, "green", cmd_define_green);
	parser_add_command(&parser->commands, 1, "blue", cmd_define_blue);

	parser_add_command(&parser->commands, 1, "radius", cmd_define_radius);
	parser_add_command(&parser->commands, 1, "ambient", cmd_define_ambient);
	parser_add_command(&parser->commands, 1, "diffuse", cmd_define_diffuse);
	parser_add_command(&parser->commands, 1, "specular", cmd_define_specular);
	parser_add_command(&parser->commands, 1, "reflection", cmd_define_reflection);
	parser_add_command(&parser->commands, 1, "refraction", cmd_define_refraction);
	parser_add_command(&parser->commands, 1, "color", cmd_define_color);
	parser_add_command(&parser->commands, 1, "intensity", cmd_define_intensity);*/

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
	parser.last_type = 0;
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
