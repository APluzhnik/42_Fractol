/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:49:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 13:42:24 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"

# define MAX_ITER	mm->max_iter
# define MOVE_X		mm->map.move_x
# define MOVE_Y		mm->map.move_y
# define ZOOM		mm->map.zoom
# define COLOR		mm->map.color
# define COLOR2		mm->map.color2
# define C_RE		mm->map.c_re
# define C_IM		mm->map.c_im
# define OLD_RE		mm->map.old_re
# define OLD_IM		mm->map.old_im
# define NEW_RE		mm->map.new_re
# define NEW_IM		mm->map.new_im
# define PR			mm->map.pr
# define PI			mm->map.pi
# define THR_ID		mm->thread_id
# define ROW		mm->row
# define COL		mm->col

# define T1			"Tab - Open menu"
# define T2			"Esc - Exit program"
# define T3			"Arrows - Move"
# define T4			"Scroll/-/+ - Zoom"
# define T5			"Backspace - Reset"
# define T6			"Num - Change fractal"
# define T7			"Extra -/+ - Change iter num"
# define T8			"F8 - Play/Stop"
# define T9			"F9 - Next"
# define T10		"F7 - Previous"
# define T11		"P - Psyhodelic"
# define T12		"C - Party"
# define T13		"B - Way effects"
# define T14		"M - Edit fractals"
# define T15		"R/G/B - Change collor"
# define T16		"Page up/down - Change collor"
# define F1			"Current: Julia"
# define F2			"Current: Mandelbrot"
# define F3			"Current: Rhombus"
# define F4			"Current: Signal"
# define F5			"Current: Shell"
# define F6			"Current: Skull"
# define F7			"Current: Onion"
# define F8			"Current: Hazard"
# define F9			"Current: Web"
# define F10		"Current: Rings"
# define F11		"Current: Smoke"
# define F12		"Current: MilkyWay"

typedef struct		s_map
{
	double			c_re;
	double			c_im;
	double			pr;
	double			pi;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			move_x;
	double			move_y;
	double			zoom;
	int				color;
	int				color2;
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_main
{
	void			*mlx;
	void			*win;
	void			*menu;
	void			*win_music;
	void			*win_effects;
	int				fd;
	int				id;
	int				id_music;
	int				thread_id;
	int				max_iter;
	char			*name;
	int				psyho;
	int				change_colors;
	int				play;
	int				move;
	int				row;
	int				r;
	int				g;
	int				b;
	t_map			map;
	t_img			img;
}					t_main;

/*
** Effects.c
*/
int					effects(t_main *mm);
void				player1(t_main *mm);
void				player2(t_main *mm);
void				rgb1(int key, t_main *mm);
void				rgb2(int key, t_main *mm);

/*
** Event_keys.c
*/
int					mlx_key_events(int key, t_main *mm);
void				move_keys(int key, t_main *mm, int x, int y);
void				arrow_keys(int key, t_main *mm);
int					fractal_keys1(int key, t_main *mm);
int					fractal_keys2(int key, t_main *mm);

/*
** Event_mouse.c
*/
int					mlx_mouse_events(int btn, int x, int y, t_main *mm);
int					mlx_mouse_move(int x, int y, t_main *mm);

/*
** Fractal[1-3].c
*/
void				fract1(t_main	*mm, int x, int y, int i);
void				fract2(t_main	*mm, int x, int y, int i);
void				fract3(t_main	*mm, int x, int y, int i);
void				fract4(t_main	*mm, int x, int y, int i);
void				fract5(t_main	*mm, int x, int y, int i);
void				fract6(t_main	*mm, int x, int y, int i);
void				fract7(t_main	*mm, int x, int y, int i);
void				fract8(t_main	*mm, int x, int y, int i);
void				fract9(t_main	*mm, int x, int y, int i);
void				fract10(t_main	*mm, int x, int y, int i);
void				fract11(t_main	*mm, int x, int y, int i);
void				fract12(t_main	*mm, int x, int y, int i);

/*
** Init.c
*/
void				init(t_main *mm);
void				init_complex(t_main *mm);
void				init_position(t_main *mm);
void				init_const(t_main *mm);

/*
** Main.c
*/
int					is_fractal(t_main *mm);
int					close_ok(t_main *mm);
void				fract_list(char *error);

/*
** Menu.c
*/
void				menu(t_main *mm);
int					menu_events1(int key, t_main *mm);
int					menu_events2(int key, t_main *mm);

/*
** Menu_text.c
*/
void				menu_usage(t_main *mm);
void				menu_curr(t_main *mm);
void				menu_list(t_main *mm);

/*
** Render.c
*/
void				*render(void *data);
void				threading(t_main *mm);
void				color(t_main *mm, int i, int y, int x);

#endif
