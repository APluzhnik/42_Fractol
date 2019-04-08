/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:57:41 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 12:41:52 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	render(t_main *mm)
{
	int		y;
	int		x;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (mm->id == 1)
				julia(mm, x, y);
			if (mm->id == 2)
				mandelbrot(mm, x, y);
		}
	}
}

void	julia(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = 1.5 * (x - WIN_W / 2) / (0.5 * ZOOM * WIN_W) + MOVE_X;
	NEW_IM = (y - WIN_H / 2) / (0.5 * ZOOM * WIN_H) + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = SQR(OLD_RE) - SQR(OLD_IM) + C_RE;
		NEW_IM = 2 * OLD_RE * OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

// z2/2 + 0.26∙z4 + c || z2/2 + z4/4 + c, c = (0.7, 1.3)
// 1 - z2 + z5/(2 + 4z) + c, c = (-0.163, 0.085)
void	mandelbrot(t_main *mm, int x, int y)
{
	int		i;

	PR = 1.5 * (x - WIN_W / 2) / (0.5 * ZOOM * WIN_W) + MOVE_X;
	PI = (y - WIN_H / 2) / (0.5 * ZOOM * WIN_H) + MOVE_Y;
	init_complex(mm);
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = SQR(OLD_RE) - SQR(OLD_IM) + PR;
		NEW_IM = 2 * OLD_RE * OLD_IM + PI;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}
