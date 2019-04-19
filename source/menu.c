/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 13:43:15 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	menu(t_main *mm)
{
	mm->menu = mlx_new_window(mm->mlx, 550, 450, "Menu");
	menu_usage(mm);
	mlx_hook(mm->menu, 2, 0, menu_events1, mm);
}

int		menu_events1(int key, t_main *mm)
{
	if (key == 48 || key == 53)
	{
		mlx_destroy_window(mm->mlx, mm->menu);
		mm->menu = NULL;
	}
	if (key == 100)
	{
		if (!(mm->play))
		{
			mm->play = 1;
			player1(mm);
		}
		else
		{
			mm->play = 0;
			system("killall afplay");
		}
	}
	menu_events2(key, mm);
	return (0);
}

int		menu_events2(int key, t_main *mm)
{
	if (key == 98)
	{
		mm->id_music--;
		if (mm->id_music < 1)
			mm->id_music = 14;
		player1(mm);
	}
	if (key == 101)
	{
		mm->id_music++;
		if (mm->id_music > 14)
			mm->id_music = 1;
		player1(mm);
	}
	if (key == 35)
		mm->psyho *= -1;
	if (key == 8)
		mm->change_colors *= -1;
	if (key == 46)
		mm->move *= -1;
	if (key == 11)
		COLOR = 318568064;
	rgb1(key, mm);
	return (0);
}
