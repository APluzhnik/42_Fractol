/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_formula.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:39:11 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 19:18:18 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
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
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	mandelbrot(t_main *mm, int x, int y)
{
	int		i;

	PR = x * 1.0 / ZOOM + MOVE_X + C_RE;
	PI = y * 1.0 / ZOOM + MOVE_Y + C_IM - 0.25;
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
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract_rhombus(t_main *mm, int x, int y)
{
	int		i;

	PR = x * 1.0 / ZOOM + MOVE_X + C_RE + 0.5;
	PI = y * 1.0 / ZOOM + MOVE_Y + C_IM - 0.2;
	i = -1;
	init_complex(mm);
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE * OLD_RE - OLD_RE + OLD_IM * OLD_IM + PR;
		NEW_IM = 2 * OLD_RE * OLD_IM -OLD_IM + PI;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract_signal(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = SQR(OLD_RE) - OLD_RE - SQR(OLD_IM) + C_RE;
		NEW_IM = OLD_IM + 2 * OLD_RE * OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract_shell(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = pow(OLD_RE, 2) - pow(OLD_IM, 2) + 0.29;
		NEW_IM = -2 * OLD_RE * OLD_IM + 0.02;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}
