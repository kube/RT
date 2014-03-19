/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:47:38 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 19:37:39 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <object.h>
#include <pthread.h>
#include <ft_input.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <stdlib.h>
#include <interpreter.h>

#include <stdio.h>
#include <stdlib.h>

static void			check_command(t_command *commands, char **command_line)
{
	while (commands)
	{
		if (ft_strequ(commands->token, *command_line))
		{
			commands->callback(command_line + 1);
			return ;
		}
		commands = commands->next;
	}
	ft_putendl_fd("ERROR! Unrecognized command.", 2);
}

static void			parse_line(char *line)
{
	char			**splited;

	splited = ft_strsplit(line, ' ');
	if (*splited)
	{
		check_command(env->interpreter.commands, splited);
		free(splited);
		free(line);
	}
}

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

static void			interpreter_init_commands(t_interpreter *interpreter)
{
	interpreter->commands = NULL;
	interpreter_add_command(&interpreter->commands, "list", command_list);
	interpreter_add_command(&interpreter->commands, "remove", command_remove);
	interpreter_add_command(&interpreter->commands, "add", command_add);
	interpreter_add_command(&interpreter->commands, "export", command_export);

	// add_command("modify", command_list);
	// add_command("	", command_tab);
}

static void			*ask_user()
{
	t_scene			*scene;
	char			*line;

	scene = env->scene;
	while (1)
	{
		get_stdin_next_line(&line);
		parse_line(line);
	}
	return (NULL);
}

int					create_interpreter_thread()
{
	interpreter_init_commands(&env->interpreter);
	if (pthread_create(&env->interpreter_thread, NULL,
		ask_user, NULL))
	{
		ft_putendl_fd("ERROR! Unable to create interpreter thread.", 2);
		return (1);
	}
	return (0);
}
