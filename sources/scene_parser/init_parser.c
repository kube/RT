/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:44:18 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:21 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_input.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <parser.h>
#include <stdlib.h>

void					parser_add_command(t_parser_command **commands,
										int indent_level, char *token,
										void (*callback)(t_parser*, char**))
{
	t_parser_command	*new_command;

	new_command = (t_parser_command*)malloc(sizeof(t_parser_command));
	new_command->token = ft_strdup(token);
	new_command->indent_level = indent_level;
	new_command->callback = callback;
	new_command->next = *commands;
	*commands = new_command;
}

void					init_scene_parser(t_parser *parser)
{
	parser->commands = NULL;
	parser_add_command(&parser->commands, 0, "camera", cmd_camera);
	parser_add_command(&parser->commands, 0, "light", cmd_add_light);
	parser_add_command(&parser->commands, 0, "plane", cmd_add_plane);
	parser_add_command(&parser->commands, 0, "cone", cmd_add_cone);
	parser_add_command(&parser->commands, 0, "sphere", cmd_add_sphere);
	parser_add_command(&parser->commands, 0, "cylinder", cmd_add_cylinder);

	parser_add_command(&parser->commands, 1, "x", cmd_define_x);
	parser_add_command(&parser->commands, 1, "y", cmd_define_y);
	parser_add_command(&parser->commands, 1, "z", cmd_define_z);

	parser_add_command(&parser->commands, 1, "rotX", cmd_define_rotx);
	parser_add_command(&parser->commands, 1, "rotY", cmd_define_roty);
	parser_add_command(&parser->commands, 1, "rotZ", cmd_define_rotz);

	parser_add_command(&parser->commands, 1, "normX", cmd_define_normx);
	parser_add_command(&parser->commands, 1, "normY", cmd_define_normy);
	parser_add_command(&parser->commands, 1, "normZ", cmd_define_normz);

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
	parser_add_command(&parser->commands, 1, "intensity", cmd_define_intensity);
}