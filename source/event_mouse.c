/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:43:33 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/16 17:14:25 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	threading(mm);
	return (0);
}

int		mlx_mouse_move(int x, int y, t_main *mm)
{
	if (mm->move == 1)
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
	threading(mm);
	return (0);
}
