/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:50:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 01:43:38 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

typedef struct				s_interpreter
{
	char					**last_command;
	struct s_command		*commands;
}							t_interpreter;

typedef struct				s_command
{
	char					*token;
	void					(*callback)(char**);
	struct s_command		*next;
}							t_command;

int			create_interpreter_thread();
void		cmd_list(char **line);
void		cmd_remove(char **line);
void		cmd_add(char **line);
void		cmd_export(char **line);
void		cmd_antialias(char **line);
void		cmd_render(char **line);
void		cmd_editmode(char **line);
void		cmd_recursivity(char **line);
void		cmd_unblock(char **line);

void		export_image(int file);
void		export_scene(int file);

#endif
