/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:01:34 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 12:11:51 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fract1(t_main *mm, int x, int y, int i)
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
				NEW_RE = SQR(OLD_RE) - SQR(OLD_IM) + C_RE;
				NEW_IM = 2 * OLD_RE * OLD_IM + C_IM;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}

void	fract2(t_main *mm, int x, int y, int i)
{
	while (++y < WIN_H / THREADS * (THR_ID + 1))
	{
		x = -1;
		while (++x < WIN_W)
		{
			i = -1;
			PR = x * 1.0 / ZOOM + MOVE_X + C_RE;
			PI = y * 1.0 / ZOOM + MOVE_Y + C_IM - 0.25;
			init_complex(mm);
			while (++i < MAX_ITER)
			{
				OLD_RE = NEW_RE;
				OLD_IM = NEW_IM;
				NEW_RE = SQR(OLD_RE) - SQR(OLD_IM) + PR;
				NEW_IM = 2 * OLD_RE * OLD_IM + PI;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}

void	fract3(t_main *mm, int x, int y, int i)
{
	while (++y < WIN_H / THREADS * (THR_ID + 1))
	{
		x = -1;
		while (++x < WIN_W)
		{
			i = -1;
			PR = x * 1.0 / ZOOM + MOVE_X + C_RE;
			PI = y * 1.0 / ZOOM + MOVE_Y + C_IM - 0.25;
			init_complex(mm);
			while (++i < MAX_ITER)
			{
				OLD_RE = NEW_RE;
				OLD_IM = NEW_IM;
				NEW_RE = OLD_RE * OLD_RE - OLD_RE + OLD_IM * OLD_IM + PR;
				NEW_IM = 2 * OLD_RE * OLD_IM - OLD_IM + PI;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}

void	fract4(t_main *mm, int x, int y, int i)
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
				NEW_RE = SQR(OLD_RE) - OLD_RE - SQR(OLD_IM) + C_RE;
				NEW_IM = OLD_IM + 2 * OLD_RE * OLD_IM + C_IM;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}

void	fract5(t_main *mm, int x, int y, int i)
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
				NEW_RE = pow(OLD_RE, 2) - pow(OLD_IM, 2) + 0.29;
				NEW_IM = -2 * OLD_RE * OLD_IM + 0.02;
				if ((SQR(NEW_RE) + SQR(NEW_IM)) > 16)
					break ;
			}
			color(mm, i, y, x);
		}
	}
}
