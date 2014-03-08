#ifndef KEYBOARD_H
# define KEYBOARD_H
# include <rt.h>

# define KEYBOARD_PLOT M_PI / 900

typedef struct			s_pressedkeys
{
	int					up;
	int					down;
	int					left;
	int					right;
	int					p_up;
	int					p_down;
}						t_pressedkeys;

#endif
