/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:30 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 11:27:59 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_main *mm)
{
	C_RE = -0.7; // 0.285 -0.8
	C_IM = 0.27015; // 0.01 0.156
	PR = 0;
	PI = 0;

	COLOR = INDIGO; //NAVY MIDNIGHTBLUE INDIGO MAROON LIME
	COLOR2 = AQUA;

	mm->win_help = NULL;

	init_position(mm);
	init_complex(mm);
}

void	init_complex(t_main *mm)
{
	NEW_RE = 0;
	NEW_IM = 0;
	OLD_RE = 0;
	OLD_IM = 0;
}

void	init_position(t_main *mm)
{
	ZOOM = 1;
	MOVE_X = 0;
	MOVE_Y = 0;
	if (mm->id == 2)
		MOVE_X = -0.5;
}
