/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:43:33 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 14:05:03 by apluzhni         ###   ########.fr       */
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
	if (key == 48)
	{
		if (mm->menu)
		{
			mlx_destroy_window(mm->mlx, mm->menu);
			mm->menu = NULL;
		}
		else
			menu(mm);
	}
	move_keys(key, mm, x, y);
	arrow_keys(key, mm);
	fractal_keys1(key, mm);
	threading(mm);
	return (0);
}

void	move_keys(int key, t_main *mm, int x, int y)
{
	if (key == 24)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM / 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM / 0.9));
		MAX_ITER++;
		ZOOM /= 0.9;
	}
	if (key == 27)
	{
		MOVE_X = (x / ZOOM + MOVE_X) - (x / (ZOOM * 0.9));
		MOVE_Y = (y / ZOOM + MOVE_Y) - (y / (ZOOM * 0.9));
		MAX_ITER--;
		ZOOM *= 0.9;
	}
	if (key == 69)
		MAX_ITER += ZOOM / 100;
	if (key == 78)
		MAX_ITER -= ZOOM / 1000;
	if (key == 51)
	{
		init_position(mm);
		init_const(mm);
	}
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

int		fractal_keys1(int key, t_main *mm)
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
	fractal_keys2(key, mm);
	return (0);
}

int		fractal_keys2(int key, t_main *mm)
{
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
	if (key == 83)
		mm->id = 11;
	if (key == 84)
		mm->id = 12;
	return (0);
}
