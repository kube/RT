/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:50:05 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 17:49:41 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define COMMENT_START_CHAR '#'

# define LAST_NONE		-1
# define LAST_CAMERA	0
# define LAST_LIGHT		1
# define LAST_OBJECT	2

typedef struct				s_parser
{
	int						last_type;
	struct s_parser_command	*commands;
}							t_parser;

typedef struct				s_parser_command
{
	char					*token;
	int						indent_level;
	void					(*callback)(struct s_parser*, char**);
	struct s_parser_command	*next;
}							t_parser_command;

void		parse_file(char *file_name);

void		cmd_add_sphere(t_parser *parser, char **line);
void		cmd_add_cone(t_parser *parser, char **line);
void		cmd_add_cylinder(t_parser *parser, char **line);
void		cmd_add_plane(t_parser *parser, char **line);
void		cmd_add_light(t_parser *parser, char **line);

void		cmd_define_x(t_parser *parser, char **line);
void		cmd_define_y(t_parser *parser, char **line);
void		cmd_define_z(t_parser *parser, char **line);

void		cmd_define_rotx(t_parser *parser, char **line);
void		cmd_define_roty(t_parser *parser, char **line);
void		cmd_define_rotz(t_parser *parser, char **line);

void		cmd_define_normx(t_parser *parser, char **line);
void		cmd_define_normy(t_parser *parser, char **line);
void		cmd_define_normz(t_parser *parser, char **line);

void		cmd_define_red(t_parser *parser, char **line);
void		cmd_define_green(t_parser *parser, char **line);
void		cmd_define_blue(t_parser *parser, char **line);

void		cmd_define_ambient(t_parser *parser, char **line);
void		cmd_define_opacity(t_parser *parser, char **line);
void		cmd_define_diffuse(t_parser *parser, char **line);
void		cmd_define_specular(t_parser *parser, char **line);
void		cmd_define_reflection(t_parser *parser, char **line);
void		cmd_define_refraction(t_parser *parser, char **line);
void		cmd_define_intensity(t_parser *parser, char **line);
void		cmd_define_color(t_parser *parser, char **line);

#endif
