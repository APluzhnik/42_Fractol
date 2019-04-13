/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:49:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 19:18:00 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"

# define MAX_ITER	mm->max_iter
# define THREADS	8
# define THR_WIDTH	150

# define MOVE_X		mm->map.moveX
# define MOVE_Y		mm->map.moveY
# define ZOOM		mm->map.zoom
# define COLOR		mm->map.color
# define COLOR2		mm->map.color2
# define C_RE		mm->map.cRe
# define C_IM		mm->map.cIm
# define OLD_RE		mm->map.oldRe
# define OLD_IM		mm->map.oldIm
# define NEW_RE		mm->map.newRe
# define NEW_IM		mm->map.newIm
# define PR			mm->map.pr
# define PI			mm->map.pi
# define THR_ID		mm->thread_id

typedef struct	s_map
{
	double		cRe;
	double		cIm;
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	double		moveX;
	double		moveY;
	double		zoom;
	int			color;
	int			color2;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_main
{
	void		*mlx;
	void		*win;
	void		*win_help;
	int			fd;
	int			id;
	int			thread_id;
	int			max_iter;
	char		*name;
	int			psyho;
	int			change_colors;
	t_map		map;
	t_img		img;
}				t_main;

/*
** Syst
*/
int		close_ok(t_main *mm);

/*
** Render
*/
void	make(t_main *mm);
void	*render(void *data);
int		is_fractal(t_main *mm);
void	fract_select(t_main *mm, int x, int y);
int		effects(t_main *mm);

/*
** Help
*/
void	win_help(t_main *mm);
int		help_close(int key, t_main *mm);
void	help_text(t_main *mm);
void	help_curr_frac(t_main *mm);
void	fract_list(char *error);

/*
** Fract'ols formula
*/
void	julia(t_main *mm, int x, int y);
void	mandelbrot(t_main *mm, int x, int y);
void	fract_rhombus(t_main *mm, int x, int y);
void	fract_signal(t_main *mm, int x, int y);
void	fract_shell(t_main *mm, int x, int y);

/*
** My fract'ols
*/
void	fract6(t_main *mm, int x, int y);
void	fract7(t_main *mm, int x, int y);
void	fract8(t_main *mm, int x, int y);
void	fract_rings(t_main *mm, int x, int y);
void	fract_web(t_main *mm, int x, int y);

/*
** Init
*/
void	init(t_main *mm);
void	init_complex(t_main *mm);
void	init_position(t_main *mm);
void	init_const(t_main *mm);

/*
** Events
*/
int		mlx_key_events(int key, t_main *mm);
int		mlx_mouse_events(int btn, int x, int y, t_main *mm);
void	arrow_keys(int key, t_main *mm);
int		mlx_mouse_move(int x, int y, t_main *mm);
int		mlx_fractals(int key, t_main *mm);

/*
** Threads
*/
void	threading(t_main *mm);

#endif
