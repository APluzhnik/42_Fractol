/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:57:41 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 13:32:41 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	threading(t_main *mm)
{
	pthread_t	thr[THREADS];
	t_main		mass[THREADS];

	THR_ID = -1;
	while (++THR_ID < THREADS)
	{
		ft_memcpy((void *)&mass[THR_ID], (void *)mm, sizeof(t_main));
		pthread_create(&thr[THR_ID], NULL, render, &mass[THR_ID]);
	}
	THR_ID = -1;
	while (++THR_ID < THREADS)
		pthread_join(thr[THR_ID], NULL);
	mlx_clear_window(mm->mlx, mm->win);
	mlx_put_image_to_window(mm->mlx, mm->win, mm->img.ptr, 0, 0);
}

void	*render(void *data)
{
	t_main	*mm;
	int		x;
	int		y;
	int		i;

	mm = (t_main*)data;
	y = WIN_H / THREADS * THR_ID - 1;
	x = 0;
	i = 0;
	(mm->id == 1) ? fract1(mm, x, y, i) : 0;
	(mm->id == 2) ? fract2(mm, x, y, i) : 0;
	(mm->id == 3) ? fract3(mm, x, y, i) : 0;
	(mm->id == 4) ? fract4(mm, x, y, i) : 0;
	(mm->id == 5) ? fract5(mm, x, y, i) : 0;
	(mm->id == 6) ? fract6(mm, x, y, i) : 0;
	(mm->id == 7) ? fract7(mm, x, y, i) : 0;
	(mm->id == 8) ? fract8(mm, x, y, i) : 0;
	(mm->id == 9) ? fract9(mm, x, y, i) : 0;
	(mm->id == 10) ? fract10(mm, x, y, i) : 0;
	(mm->id == 11) ? fract11(mm, x, y, i) : 0;
	(mm->id == 12) ? fract12(mm, x, y, i) : 0;
	return (data);
}

void	color(t_main *mm, int i, int y, int x)
{
	if (x < WIN_W && y < WIN_H)
	{
		if (i != MAX_ITER)
			*(mm->img.data + (y * WIN_W + x)) = COLOR * i;
		else
			*(mm->img.data + (y * WIN_W + x)) = COLOR;
	}
}
