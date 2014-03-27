# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/24 16:52:10 by cfeijoo           #+#    #+#              #
#    Updated: 2014/03/27 20:12:23 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
INCLUDEFOLDERS = ./includes/

SOURCES_FOLDER = sources/
OBJECTS_FOLDER = objects/

SOURCES_STRINGS = \
			strings/ft_strchr.c			\
			strings/ft_strlcat.c		\
			strings/ft_strrchr.c		\
			strings/ft_strclr.c			\
			strings/ft_strlen.c			\
			strings/ft_strsplit.c		\
			strings/ft_strcmp.c			\
			strings/ft_strmap.c			\
			strings/ft_strstr.c			\
			strings/ft_strdel.c			\
			strings/ft_strncat.c		\
			strings/ft_strtrim.c		\
			strings/ft_strcpy.c			\
			strings/ft_strmapi.c		\
			strings/ft_strsub.c			\
			strings/ft_strcat.c			\
			strings/ft_strjoin.c		\
			strings/ft_striter.c		\
			strings/ft_striteri.c		\
			\
			strings/ft_strnew.c			\
			strings/ft_strdup.c			\
			strings/ft_strncmp.c		\
			strings/ft_strncpy.c		\
			strings/ft_strnstr.c		\
			strings/ft_strequ.c			\
			strings/ft_strnequ.c		\
			\
			strings/ft_strbeginwith.c	\
			strings/ft_strisnum.c		\
			strings/ft_strinarray.c		\
			strings/ft_isprint.c		\
			strings/ft_isalnum.c		\
			strings/ft_isalpha.c		\
			strings/ft_isascii.c		\
			strings/ft_isdigit.c		\

SOURCES_MEMORY = \
			memory/ft_memset.c			\
			memory/ft_memdel.c			\
			memory/ft_memmove.c			\
			memory/ft_memalloc.c		\
			memory/ft_memccpy.c			\
			memory/ft_memcmp.c			\
			memory/ft_memdup.c			\
			memory/ft_memcpy.c			\
			memory/ft_memchr.c			\
			memory/ft_bzero.c			\

SOURCES_LISTS = \
			lists/ft_lstfreeto.c		\
			lists/ft_lstadd.c			\
			lists/ft_lstqueueadd.c		\
			lists/ft_lstiter.c			\
			lists/ft_lstnew.c			\
			lists/ft_lstdel.c			\
			lists/ft_lstdelone.c		\
			lists/ft_lstmap.c			\
			lists/ft_lstrev.c			\

SOURCES_PRINT = \
			print/ft_putstr_fd.c		\
			print/ft_putnbrb.c			\
			print/ft_putlnbr.c			\
			print/ft_putchar.c			\
			print/ft_putchar_fd.c		\
			print/ft_putendl.c			\
			print/ft_putendl_fd.c		\
			print/ft_putnbr.c			\
			print/ft_putunbr.c			\
			print/ft_putstr.c			\
			print/ft_putnbr_fd.c		\
			print/ft_putunbr_fd.c		\
			print/exit_with_error.c		\

SOURCES_CONVERT = \
			convert/ft_abs.c			\
			convert/ft_atoi.c			\
			convert/ft_itoa.c			\
			convert/ft_tolower.c		\
			convert/ft_toupper.c		\
			convert/hash.c				\

SOURCES_INPUT = \
			input/ft_getchar.c			\
			input/get_stdin_next_line.c	\
			input/get_next_line.c		\

SOURCES_MATH = \
			math/ft_sqrt.c					\
			math/ft_cossin.c				\
			math/vector_transformations.c	\
			math/vector_properties.c		\
			math/infin_add.c				\
			math/print_infin_number.c		\
			math/infin_number_gt.c			\
			math/load_infin_number.c		\
			math/vector_operations.c		\

SOURCES_COLORS = \
			colors/blend_colors.c			\
			colors/fade_color.c				\
			colors/color_blend_over.c		\
			colors/color_blend_add.c		\
			colors/color_blend_sub.c		\

SOURCES_HASHMAP = \
			hashmap/hashmap.c				\

SOURCES = 	$(SOURCES_CONVERT) $(SOURCES_INPUT) $(SOURCES_LISTS) \
			$(SOURCES_MATH) $(SOURCES_MEMORY) $(SOURCES_PRINT) \
			$(SOURCES_STRINGS) $(SOURCES_COLORS) $(SOURCES_HASHMAP)

OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(subst /,__,$(OBJECTS))
OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

CC = clang
AR = ar
CFLAGS = -Wall -Werror -Wextra


# Colors

NO_COLOR =		\x1b[0m
OK_COLOR =		\x1b[32;01m
ERROR_COLOR =	\x1b[31;01m
WARN_COLOR =	\x1b[33;01m
SILENT_COLOR =	\x1b[30;01m


# Basic Rules

.PHONY: all re clean fclean

all: $(NAME)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) -I$(INCLUDEFOLDERS) $(CFLAGS) $(MACROS) -o $@
	@printf "$(OK_COLOR)✓ $(NO_COLOR)"
	@echo "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@)))"

$(NAME): $(OBJECTS)
	@printf "$(SILENT_COLOR)Compiling LibFt...$(NO_COLOR)"
	@$(AR) rcs $(NAME).a $(OBJECTS)
	@echo " $(OK_COLOR)Successful ✓$(NO_COLOR)"

clean:
	@rm -f $(OBJECTS)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Objects$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME).a
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Library$(NO_COLOR)"

re: fclean all


# Special Rules

usemath:
	@echo "$(WARN_COLOR)Compiling LibFt using Math.h$(NO_COLOR)"
	$(eval MACROS := "-D USE_MATH=1")