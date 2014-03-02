NAME = rt

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/
LIBFOLDERS = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lmlx -lXext -lX11 -lft

CC = clang
CFLAGS = -Wall -Werror -Wextra

SOURCES =	sources/rt.c							\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)

updatelibs :
	cd libft/ && git pull
	make -C libft/ re

complibs :
	make -C libft/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
