/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 13:40:20 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	menu_usage(t_main *mm)
{
	ROW = 10;
	mlx_string_put(mm->mlx, mm->menu, 100, ROW, RED, "Usage");
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T1);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T2);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T3);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T4);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T5);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T6);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T7);
	mlx_string_put(mm->mlx, mm->menu, 100, ROW += 35, RED, "Music");
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T8);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T9);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T10);
	mlx_string_put(mm->mlx, mm->menu, 100, ROW += 35, RED, "Effects");
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T11);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T12);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T13);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T14);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T15);
	mlx_string_put(mm->mlx, mm->menu, 10, ROW += 20, YELLOW, T16);
	menu_curr(mm);
}

void	menu_curr(t_main *mm)
{
	if (mm->id == 1)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F1);
	if (mm->id == 2)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F2);
	if (mm->id == 3)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F3);
	if (mm->id == 4)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F4);
	if (mm->id == 5)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F5);
	if (mm->id == 6)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F6);
	if (mm->id == 7)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F7);
	if (mm->id == 8)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F8);
	if (mm->id == 9)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F9);
	if (mm->id == 10)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F10);
	if (mm->id == 11)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F11);
	if (mm->id == 12)
		mlx_string_put(mm->mlx, mm->menu, 300, 10, GREEN, F12);
	menu_list(mm);
}

void	menu_list(t_main *mm)
{
	ROW = 10;
	mlx_string_put(mm->mlx, mm->menu, 400, ROW += 35, RED, "Fractals");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "1. Julia");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "2. Mandelbrot");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "3. Rhombus");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "4. Signal");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "5. Shell");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "6. Skull");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "7. Onion");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "8. Hazard");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "9. Web");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "10.Rings");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "11.Smoke");
	mlx_string_put(mm->mlx, mm->menu, 300, ROW += 20, BLUE, "12.MilkyWay");
}
