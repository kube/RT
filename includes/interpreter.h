/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:50:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 22:55:50 by cfeijoo          ###   ########.fr       */
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
	struct s_command		*child;
	void					(*callback)(char**);
	struct s_command		*next;
}							t_command;

int			create_interpreter_thread();
void		command_list(char **line);
void		command_remove(char **line);
void		command_add(char **line);
void		command_export(char **line);

#endif
