/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:57:41 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 19:18:13 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	make(t_main *mm)
{
	mlx_clear_window(mm->mlx, mm->win);
	threading(mm);
	mlx_put_image_to_window(mm->mlx, mm->win, mm->img.ptr, 0, 0);
}

void	*render(void *data)
{
	t_main	*mm;
	int		y;
	int		x;

	mm = (t_main*)data;
	y = WIN_H / THREADS * THR_ID - 1;
	while (++y < WIN_H / THREADS * (THR_ID + 1))
	{
		x = -1;
		while (++x < WIN_W)
		{
			fract_select(mm, x, y);
		}
	}
	return (data);
}

int		is_fractal(t_main *mm)
{
	if (!(ft_strcmp(mm->name, "Julia")))
		return (1);
	if (!(ft_strcmp(mm->name, "Mandelbrot")))
		return (2);
	if (!(ft_strcmp(mm->name, "Rhombus")))
		return (3);
	if (!(ft_strcmp(mm->name, "Signal")))
		return (4);
	if (!(ft_strcmp(mm->name, "Shell")))
		return (5);
	if (!(ft_strcmp(mm->name, "6")))
		return (6);
	if (!(ft_strcmp(mm->name, "7")))
		return (7);
	if (!(ft_strcmp(mm->name, "8")))
		return (8);
	if (!(ft_strcmp(mm->name, "Web")))
		return (9);
	if (!(ft_strcmp(mm->name, "Rings")))
		return (10);
	return (0);
}

void	fract_select(t_main *mm, int x, int y)
{
	if (mm->id == 1)
		julia(mm, x, y);
	if (mm->id == 2)
		mandelbrot(mm, x, y);
	if (mm->id == 3)
		fract_rhombus(mm, x, y);
	if (mm->id == 4)
		fract_signal(mm, x, y);
	if (mm->id == 5)
		fract_shell(mm, x, y);
	if (mm->id == 6)
		fract6(mm, x, y);
	if (mm->id == 7)
		fract7(mm, x, y);
	if (mm->id == 8)
		fract8(mm, x, y);
	if (mm->id == 9)
		fract_web(mm, x, y);
	if (mm->id == 10)
		fract_rings(mm, x, y);
}


int		effects(t_main *mm)
{
	int		sector;

	if (mm->psyho == 1)
	{
		COLOR += 004000100;
		make(mm);
	}
	if (mm->change_colors == 1)
	{
		sector = rand() % 10;
		(sector == 0) ? COLOR = 1050370 : 1;
		(sector == 1) ? COLOR = 526849 : 1;
		(sector == 2) ? COLOR = 002001006 : 1;
		(sector == 3) ? COLOR = 004001006 : 1;
		(sector == 4) ? COLOR = 262662 : 1;
		(sector == 5) ? COLOR = 001001001 : 1;
		(sector == 6) ? COLOR = 001001006 : 1;
		(sector == 7) ? COLOR = 004002007 : 1;
		(sector == 8) ? COLOR = 000002004 : 1;
		(sector == 9) ? COLOR = 002004005 : 1;
		make(mm);
	}
	return (0);
}

