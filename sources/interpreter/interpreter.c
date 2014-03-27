/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:47:38 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 18:15:49 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <object.h>
#include <pthread.h>
#include <ft_input.h>
#include <stdlib.h>
#include <ft_print.h>
#include <ft_strings.h>
#include <interpreter.h>
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
