/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:57:41 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/07 16:44:28 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	win_help(t_main *mm)
{
	mm->win_help = mlx_new_window(mm->mlx, 300, 300, "Help");
	help_text(mm);
	mlx_hook(mm->win_help, 2, 0, help_close, mm);
}

int		help_close(int key, t_main *mm)
{
	if (key == 122 || key == 53)
	{
		mlx_destroy_window(mm->mlx, mm->win_help);
		mm->win_help = NULL;
	}
	return (0);
}

void	help_text(t_main *mm)
{
	mlx_string_put(mm->mlx, mm->win_help, 100, 10, WHITE, "Usage");
	mlx_string_put(mm->mlx, mm->win_help, 10, 30, WHITE, "Open help - F1");
	mlx_string_put(mm->mlx, mm->win_help, 10, 50, WHITE, "Exit program - Esc");
	mlx_string_put(mm->mlx, mm->win_help, 10, 70, WHITE, "Move - Arrows");
	mlx_string_put(mm->mlx, mm->win_help, 10, 90, WHITE, "Zoom - Scroll or +/-");
	// mlx_string_put(mm->mlx, mm->win_help, 10, 110, WHITE, "Change fractal - 1/2/3");
	help_curr_frac(mm);
	mlx_string_put(mm->mlx, mm->win_help, 100, 170, YELLOW, "Fractals");
	mlx_string_put(mm->mlx, mm->win_help, 10, 190, YELLOW, "1. Julia");
	mlx_string_put(mm->mlx, mm->win_help, 10, 210, YELLOW, "2. Mandelbrot");
}

void	help_curr_frac(t_main *mm)
{
	if (mm->id == 1)
		mlx_string_put(mm->mlx, mm->win_help, 10, 140, GREEN, "Current: Julia");
	if (mm->id == 2)
		mlx_string_put(mm->mlx, mm->win_help, 10, 140, GREEN, "Current: Mandelbrot");
}
