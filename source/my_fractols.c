/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fractols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:39:11 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 17:45:04 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fract6(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE + C_RE;
		NEW_IM = OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract7(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE + C_RE;
		NEW_IM = OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract8(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE + C_RE;
		NEW_IM = OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract_rings(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE + OLD_IM + C_RE;
		NEW_IM = OLD_RE - OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}

void	fract_web(t_main *mm, int x, int y)
{
	int		i;

	NEW_RE = x * 1.0 / ZOOM + MOVE_X;
	NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
	i = -1;
	while (++i < MAX_ITER)
	{
		OLD_RE = NEW_RE;
		OLD_IM = NEW_IM;
		NEW_RE = OLD_RE * OLD_IM + C_RE;
		NEW_IM = OLD_RE + OLD_IM + C_IM;
		if((SQR(NEW_RE) + SQR(NEW_IM)) > 16) break;
	}
	if (i != MAX_ITER)
		*(mm->img.data + (y * WIN_W + x)) = COLOR * i / 100;
	else
		*(mm->img.data + (y * WIN_W + x)) = COLOR2 * i;
}
