/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:43:33 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 12:43:34 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mlx_key_events(int key, t_main *mm)
{
	if (key == 53)
		close_ok(mm);
	if (key == 24 || key == 69) // +
	{
		ZOOM += 0.01;
		make(mm);
	}
	if (key == 27 || key == 78) // -
	{
		if (ZOOM > 0)
			ZOOM -= 0.01;
		make(mm);
	}
	if (key == 122) // f1
	{
		if (mm->win_help)
		{
			mlx_destroy_window(mm->mlx, mm->win_help);
			mm->win_help = NULL;
		}
		else
			win_help(mm);
	}
	if (key == 51) // backspace
	{
		ZOOM = 1;
		MOVE_X = 0;
		MOVE_Y = 0;
		make(mm);
	}
	arrow_keys(key, mm);
	return (0);
}

void	arrow_keys(int key, t_main *mm)
{
	if (key == 123) // left
	{
		MOVE_X += 0.01;
		make(mm);
	}
	if (key == 124) // right
	{
		MOVE_X -= 0.01;
		make(mm);
	}
	if (key == 125) // down
	{
		MOVE_Y -= 0.01;
		make(mm);
	}
	if (key == 126) // up
	{
		MOVE_Y += 0.01;
		make(mm);
	}
}

int		mlx_mouse_events(int btn, int x, int y, t_main *mm)
{
	(void)x;
	(void)y;
	if (btn == 5)
	{
		ZOOM += 0.01;
		make(mm);
	}
	if (btn == 4)
	{
		if (ZOOM > 0)
			ZOOM -= 0.01;
		make(mm);
	}
	return (0);
}

void	make(t_main *mm)
{
	mlx_clear_window(mm->mlx, mm->win);
	render(mm);
	mlx_put_image_to_window(mm->mlx, mm->win, mm->img.ptr, 0, 0);
}
