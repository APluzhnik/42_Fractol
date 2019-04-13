/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:30 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 18:55:22 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_main *mm)
{
	init_const(mm);
	MAX_ITER = 150;
	COLOR = 318568064; // WHITE NAVY MIDNIGHTBLUE INDIGO MAROON LIME AQUA
	COLOR2 = BLACK;
	mm->psyho = -1;
	mm->change_colors = -1;
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
	ZOOM = 500;
	MOVE_X = -1.5;
	MOVE_Y = -1;
}

void	init_const(t_main *mm)
{
	C_RE = -0.7;
	C_IM = 0.27015;
	PR = 0;
	PI = 0;
}
