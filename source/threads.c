/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:48:56 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/09 14:26:23 by apluzhni         ###   ########.fr       */
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
}
