/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:30 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 14:07:10 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_main *mm)
{
	init_const(mm);
	MAX_ITER = 100;
	COLOR = 268568064;
	COLOR2 = BLACK;
	mm->psyho = -1;
	mm->change_colors = -1;
	mm->menu = NULL;
	mm->row = 10;
	mm->play = 0;
	mm->id_music = 1;
	mm->move = 1;
	mm->r = 0;
	mm->g = 0;
	mm->b = 0;
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
