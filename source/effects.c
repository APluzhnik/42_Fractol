/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 12:22:43 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		effects(t_main *mm)
{
	int		sector;

	if (mm->psyho == 1)
	{
		COLOR += 004000100;
		threading(mm);
	}
	if (mm->change_colors == 1)
	{
		sector = rand() % 10;
		(sector == 0) ? COLOR = 1050370 : 1;
		(sector == 1) ? COLOR = 526849 : 1;
		(sector == 2) ? COLOR = 002001006 : 1;
		(sector == 3) ? COLOR = 004001006 : 1;
		(sector == 4) ? COLOR = 262662 : 1;
		(sector == 5) ? COLOR = 001001001 : 1;
		(sector == 6) ? COLOR = 001001006 : 1;
		(sector == 7) ? COLOR = 004002007 : 1;
		(sector == 8) ? COLOR = 000002004 : 1;
		(sector == 9) ? COLOR = 002004005 : 1;
		threading(mm);
	}
	return (0);
}

void	player1(t_main *mm)
{
	system("killall afplay");
	if (mm->id_music == 1)
		system("afplay music/MOLOKOPLUS.mp3&");
	if (mm->id_music == 2)
		system("afplay music/RussianBoy.mp3&");
	if (mm->id_music == 3)
		system("afplay music/BadmanGang.mp3&");
	if (mm->id_music == 4)
		system("afplay music/GANG.mp3&");
	if (mm->id_music == 5)
		system("afplay music/Sorta.mp3&");
	if (mm->id_music == 6)
		system("afplay music/Zombie.mp3&");
	player2(mm);
}

void	player2(t_main *mm)
{
	if (mm->id_music == 7)
		system("afplay music/ThankGodMyBitchBad.mp3&");
	if (mm->id_music == 8)
		system("afplay music/MilkyWay.mp3&");
	if (mm->id_music == 9)
		system("afplay music/BasicInstincts.mp3&");
	if (mm->id_music == 10)
		system("afplay music/Ringing.mp3&");
	if (mm->id_music == 11)
		system("afplay music/TicToc.mp3&");
	if (mm->id_music == 12)
		system("afplay music/FeelingAWay.mp3&");
	if (mm->id_music == 13)
		system("afplay music/Morocco.mp3&");
	if (mm->id_music == 14)
		system("afplay music/MOLOKOPLUSFOREVER.mp3&");
}

void	rgb1(int key, t_main *mm)
{
	if (key == 15)
	{
		mm->r = 1;
		mm->g = 0;
		mm->b = 0;
	}
	if (key == 5)
	{
		mm->r = 0;
		mm->g = 1;
		mm->b = 0;
	}
	if (key == 11)
	{
		mm->r = 0;
		mm->g = 0;
		mm->b = 1;
	}
	rgb2(key, mm);
}

void	rgb2(int key, t_main *mm)
{
	if (key == 116)
	{
		if (mm->r)
			COLOR += 0x100000;
		if (mm->g)
			COLOR += 0x001000;
		if (mm->b)
			COLOR += 0x000010;
		threading(mm);
	}
	if (key == 121)
	{
		if (mm->r)
			COLOR -= 0x100000;
		if (mm->g)
			COLOR -= 0x001000;
		if (mm->b)
			COLOR -= 0x000010;
		threading(mm);
	}
}
