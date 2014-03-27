/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 00:50:05 by kube              #+#    #+#             */
/*   Updated: 2014/03/27 14:39:00 by cfeijoo          ###   ########.fr       */
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

#endif
