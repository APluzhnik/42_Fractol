/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:01:34 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 12:11:56 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fract11(t_main *mm, int x, int y, int i)
{
	while (++y < WIN_H / THREADS * (THR_ID + 1))
	{
		x = -1;
		while (++x < WIN_W)
		{
			i = -1;
			NEW_RE = x * 1.0 / ZOOM + MOVE_X;
			NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
			while (++i < MAX_ITER)
			{
				OLD_RE = NEW_RE;
				OLD_IM = NEW_IM;
				NEW_RE = OLD_RE / cos(OLD_IM) + C_RE;
				NEW_IM = OLD_IM / sin(OLD_RE) - C_IM;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}

void	fract12(t_main *mm, int x, int y, int i)
{
	while (++y < WIN_H / THREADS * (THR_ID + 1))
	{
		x = -1;
		while (++x < WIN_W)
		{
			i = -1;
			NEW_RE = x * 1.0 / ZOOM + MOVE_X;
			NEW_IM = y * 1.0 / ZOOM + MOVE_Y;
			while (++i < MAX_ITER)
			{
				OLD_RE = NEW_RE;
				OLD_IM = NEW_IM;
				NEW_RE = OLD_RE * OLD_RE - OLD_IM * OLD_IM + PR;
				NEW_IM = 2 * OLD_RE * OLD_IM + PI;
				PR = -cos(NEW_IM) - sin(NEW_IM) + 0.1;
				PI = sin(NEW_RE);
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}
