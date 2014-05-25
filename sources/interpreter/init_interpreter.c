/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interpreter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:12:41 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/05/15 02:03:00 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <interpreter.h>
#include <ft_print.h>
#include <ft_strings.h>

static void			interpreter_add_command(t_command **commands, char *token,
											void (*callback)(char**))
{
	t_command		*new_command;

	new_command = (t_command*)malloc(sizeof(t_command));
	new_command->token = ft_strdup(token);
	new_command->callback = callback;
	new_command->next = *commands;
	*commands = new_command;
}

void		interpreter_init_commands(t_interpreter *interpreter)
{
	interpreter->commands = NULL;
	interpreter_add_command(&interpreter->commands, "list", cmd_list);
	interpreter_add_command(&interpreter->commands, "remove", cmd_remove);
	interpreter_add_command(&interpreter->commands, "add", cmd_add);
	interpreter_add_command(&interpreter->commands, "export", cmd_export);
	interpreter_add_command(&interpreter->commands, "antialias", cmd_antialias);
	interpreter_add_command(&interpreter->commands, "render", cmd_render);
	interpreter_add_command(&interpreter->commands, "edit_mode", cmd_editmode);
	interpreter_add_command(&interpreter->commands, "recursion",
							cmd_recursivity);
	interpreter_add_command(&interpreter->commands, "unblock", cmd_unblock);
}
