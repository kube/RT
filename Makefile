# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 14:37:36 by cfeijoo           #+#    #+#              #
#    Updated: 2014/03/17 20:05:09 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = rt

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/ -I/opt/X11/include/X11/
LIBFOLDERS = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lmlx -lXext -lX11 -lft -lm -lpthread

CC = clang
CFLAGS = -Wall  -Werror -Wextra -O3

SOURCES_FOLDER = sources/
OBJECTS_FOLDER = objects/

SOURCES =	rt.c								\
			camera/camera_transformations.c		\
			camera/camera_init.c				\
			object/creation.c					\
			scene_parser/parser.c				\
			interpreter/interpreter.c			\
			interpreter/command_list.c			\
			interpreter/command_remove.c		\
			interpreter/command_add.c			\
			mouse/mouse.c						\
			ray_throw.c							\
			equations.c							\
			phong_shading.c						\
			matter.c							\
			render_thread.c						\
			light_diaphragm.c					\
			keyboard.c							\
			pixel.c								\

OBJECTS =	$(SOURCES:.c=.o)

OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(subst /,__,$(OBJECTS))
OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

# Colors
NO_COLOR =		\x1b[0m
OK_COLOR =		\x1b[32;01m
ERROR_COLOR =	\x1b[31;01m
WARN_COLOR =	\x1b[33;01m
SILENT_COLOR =	\x1b[30;01m

.PHONY: all re clean fclean

all: $(NAME)

linux :
	@$(eval INCLUDEFOLDERS := -I./includes/ -I./libft/includes/ -I/usr/X11/include/ -I/usr/include/X11)
	@$(eval LIBFOLDERS := -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) $(INCLUDEFOLDERS) $(CFLAGS) $(MACROS) -o $@
	@printf "$(OK_COLOR)✓ $(NO_COLOR)"
	@echo "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@)))"

$(NAME) : $(OBJECTS)
	@printf "$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(OBJECTS) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)
	@echo " $(OK_COLOR)Successful ✓$(NO_COLOR)"

getlibs :
	git clone https://github.com/kubekhrm/libft.git

updatelibs :
	@echo "$(SILENT_COLOR)Searching LibFt updates...$(NO_COLOR)"
	@cd libft/ && git pull

complibs :
	@make -C libft/ usemath nothing addmath addconvert addprint addinput addmemory addstrings addcolors re

clean :
	@rm -f $(OBJECTS)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Objects$(NO_COLOR)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Program$(NO_COLOR)"
	# @make -C "libft/" fclean

re : fclean all
