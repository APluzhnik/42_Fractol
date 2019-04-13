/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:43:33 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 18:56:02 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mlx_key_events(int key, t_main *mm)
{
	int		x;
	int		y;

	x = WIN_W / 2;
	y = WIN_H / 2;
	if (key == 53)
		close_ok(mm);
	if (key == 24 || key == 69)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM / 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM / 0.9));
		MAX_ITER++;
		ZOOM /= 0.9;
	}
	if (key == 27 || key == 78)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM * 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM * 0.9));
		MAX_ITER--;
		ZOOM *= 0.9;
	}
	if (key == 48)
	{
		if (mm->win_help)
		{
			mlx_destroy_window(mm->mlx, mm->win_help);
			mm->win_help = NULL;
		}
		else
			win_help(mm);
	}
	if (key == 51)
	{
		init_position(mm);
		init_const(mm);
	}
	if (key == 35)
		mm->psyho *= -1;
	if (key == 8)
		mm->change_colors *= -1;
	arrow_keys(key, mm);
	mlx_fractals(key, mm);
	make(mm);
	return (0);
}

void	arrow_keys(int key, t_main *mm)
{
	if (key == 123)
	{
		MOVE_X -= 20 / ZOOM;
	}
	if (key == 124)
	{
		MOVE_X += 20 / ZOOM;
	}
	if (key == 125)
	{
		MOVE_Y += 20 / ZOOM;
	}
	if (key == 126)
	{
		MOVE_Y -= 20 / ZOOM;
	}
}

int		mlx_mouse_events(int btn, int x, int y, t_main *mm)
{
	if (btn == 5)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM / 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM / 0.9));
		MAX_ITER++;
		ZOOM /= 0.9;
	}
	if (btn == 4)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM * 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM * 0.9));
		MAX_ITER--;
		ZOOM *= 0.9;
	}
	make(mm);
	return (0);
}

int		mlx_mouse_move(int x, int y, t_main *mm)
{
	if (mm->id == 1)
	{
		if (x > 1280)
			C_RE = 0.001 * x;
		else
			C_RE = 0.001 * x;
		if (y > 720)
			C_IM = 0.001 * y;
		else
			C_IM = 0.001 * y;
	}
	make(mm);
	return (0);
}

int		mlx_fractals(int key, t_main *mm)
{
	if ((key >= 18 && key <= 29) && key != 24 && key != 27)
		init(mm);
	if (key == 18)
		mm->id = 1;
	if (key == 19)
		mm->id = 2;
	if (key == 20)
		mm->id = 3;
	if (key == 21)
		mm->id = 4;
	if (key == 23)
		mm->id = 5;
	if (key == 22)
		mm->id = 6;
	if (key == 26)
		mm->id = 7;
	if (key == 28)
		mm->id = 8;
	if (key == 25)
		mm->id = 9;
	if (key == 29)
		mm->id = 10;
	return (0);
}
