#ifndef KEYBOARD_H
# define KEYBOARD_H
# include <rt.h>

# define KEYBOARD_ROT_PLOT M_PI / 1100
# define KEYBOARD_MOV_PLOT 0.045

typedef struct			s_pressedkeys
{
	int					up;
	int					down;
	int					left;
	int					right;
	int					p_up;
	int					p_down;
	int					num_plus;
	int					num_minus;
	int					w;
	int					a;
	int					s;
	int					d;
	int					del;
	int					shift;
	int					ctrl;
	int					alt;
	int					tab;
	int					space;
}						t_pressedkeys;

int			is_one_key_pressed(t_pressedkeys *keys);
void		init_pressed_keys(t_pressedkeys *keys);
int			keypress_hook(int keycode, t_pressedkeys *keys);
void		check_pressed_keys(t_pressedkeys *keys);
int			keyrelease_hook(int keycode, t_pressedkeys *keys);

#endif
