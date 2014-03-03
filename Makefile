# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 14:37:36 by cfeijoo           #+#    #+#              #
#    Updated: 2014/03/02 17:37:14 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = rt

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/
LIBFOLDERS = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lmlx -lXext -lX11 -lft

CC = clang
CFLAGS = -Wall -Werror -Wextra

SOURCES_FOLDER = sources/
OBJECTS_FOLDER = objects/

SOURCES =	\
			rt.c			\

OBJECTS =	$(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

# Colors
NO_COLOR =		\x1b[0m
OK_COLOR =		\x1b[32;01m
ERROR_COLOR =	\x1b[31;01m
WARN_COLOR =	\x1b[33;01m
SILENT_COLOR =	\x1b[30;01m

.PHONY: all re clean fclean

all: complibs $(NAME)

$(OBJECTS) : $(SOURCES)
	@$(CC) -c $< $(INCLUDEFOLDERS) $(CFLAGS) -o $@
	@printf "$(OK_COLOR)✓ $(NO_COLOR)"
	@echo "$<"

$(NAME) : $(OBJECTS)
	@printf "$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(OBJECTS) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)
	@echo " $(OK_COLOR)Successful ✓$(NO_COLOR)"

updatelibs :
	@echo "$(SILENT_COLOR)Searching LibFt updates...$(NO_COLOR)"
	@cd libft/ && git pull

complibs :
	@make -C libft/ usemath all

clean :
	@rm -f $(OBJECTS)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Objects$(NO_COLOR)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Program$(NO_COLOR)"
	@make -C "libft/" fclean

re : fclean all
