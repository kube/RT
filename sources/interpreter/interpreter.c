/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:47:38 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 03:37:35 by cfeijoo          ###   ########.fr       */
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


static void			check_command(t_env *env, t_command *commands,
									char **command_line)
{
	while (commands)
	{
		if (ft_strequ(commands->token, *command_line))
		{
			commands->f(env, command_line + 1);
			return ;
		}
		commands = commands->next;
	}
	ft_putendl_fd("ERROR! Unrecognized command.", 2);
}

static void			parse_line(t_env *env, char *line)
{
	char			**splited;

	splited = ft_strsplit(line, ' ');
	if (*splited)
	{
		check_command(env, env->interpreter.commands, splited);
		free(splited);
		free(line);
	}
}


static void			interpreter_add_command(t_command **commands, char *token,
											void (*f)(t_env*, char**))
{
	t_command		*new_command;

	new_command = (t_command*)malloc(sizeof(t_command));
	new_command->token = ft_strdup(token);
	new_command->f = f;
	new_command->next = *commands;
	*commands = new_command;
}

static void			interpreter_init_commands(t_interpreter *interpreter)
{
	interpreter->commands = NULL;
	interpreter_add_command(&interpreter->commands, "list", command_list);
	interpreter_add_command(&interpreter->commands, "remove", command_remove);
	interpreter_add_command(&interpreter->commands, "add", command_add);
	// add_command("repeat", command_repeat);
	// add_command("modify", command_list);
	// add_command("	", command_tab);
}

static void			*ask_user(void *env_input)
{
	t_env			*env;
	t_scene			*scene;
	char			*line;

	env = (t_env*)env_input;
	scene = env->scene;
	while (1)
	{
		get_stdin_next_line(&line);
		parse_line(env, line);
	}
	return (NULL);
}

int					create_interpreter_thread(t_env *env)
{
	interpreter_init_commands(&env->interpreter);
	if (pthread_create(&env->interpreter_thread, NULL,
		ask_user, (void*)env))
	{
		ft_putendl_fd("ERROR! Unable to create interpreter thread.", 2);
		return (1);
	}
	return (0);
}
