# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 14:37:36 by cfeijoo           #+#    #+#              #
#    Updated: 2014/03/27 17:50:17 by acollin          ###   ########.fr        #
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

SOURCES =	rt.c									\
			camera/camera_transformations.c			\
			camera/camera_init.c					\
			object/creation.c						\
			scene_parser/parser.c					\
			scene_parser/command_add_sphere.c		\
			scene_parser/command_add_cone.c			\
			scene_parser/command_add_cylinder.c		\
			scene_parser/command_add_plane.c		\
			scene_parser/command_add_light.c		\
			scene_parser/command_define_xyz.c		\
			scene_parser/command_define_rotxyz.c	\
			scene_parser/command_define_normxyz.c	\
			scene_parser/command_define_rgb.c		\
			scene_parser/command_define_radius.c	\
			scene_parser/command_define_ambient.c	\
			scene_parser/command_define_opacity.c	\
			scene_parser/command_define_diffuse.c	\
			scene_parser/command_define_specular.c	\
			scene_parser/command_define_refraction.c\
			scene_parser/command_define_intensity.c	\
			scene_parser/command_define_color.c		\
			interpreter/interpreter.c			\
			interpreter/command_list.c			\
			interpreter/command_remove.c		\
			interpreter/command_add.c			\
			interpreter/command_export.c		\
			interpreter/command_antialias.c		\
			interpreter/command_render.c		\
			interpreter/command_editmode.c		\
			interpreter/command_recursivity.c	\
			interpreter/command_unblock.c	\
			export/export_image.c				\
			mouse/mouse.c						\
			ray_throw.c							\
			equations/equation_cone.c			\
			equations/equation_cylinder.c		\
			equations/equation_sphere.c			\
			equations/equation_plane.c			\
			equations/positive_smallest.c		\
			equations/matrix.c					\
			equations/change_ray.c				\
			phong_shading.c						\
			matter.c							\
			render_thread.c						\
			render_to_image.c					\
			light_diaphragm.c					\
			keyboard.c							\
			pixel.c								\
			\
			tests.c								\

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
