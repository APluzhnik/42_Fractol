/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:57:41 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 19:17:32 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	win_help(t_main *mm)
{
	mm->win_help = mlx_new_window(mm->mlx, 300, 500, "Help");
	help_text(mm);
	mlx_hook(mm->win_help, 2, 0, help_close, mm);
}

int		help_close(int key, t_main *mm)
{
	if (key == 48 || key == 53)
	{
		mlx_destroy_window(mm->mlx, mm->win_help);
		mm->win_help = NULL;
	}
	return (0);
}

void	help_text(t_main *mm)
{
	mlx_string_put(mm->mlx, mm->win_help, 100, 10, BLUE, "Usage");
	mlx_string_put(mm->mlx, mm->win_help, 10, 30, WHITE, "Open help - Tab");
	mlx_string_put(mm->mlx, mm->win_help, 10, 50, WHITE, "Exit program - Esc");
	mlx_string_put(mm->mlx, mm->win_help, 10, 70, WHITE, "Move - Arrows");
	mlx_string_put(mm->mlx, mm->win_help, 10, 90, WHITE, "Zoom - Scroll or +/-");
	mlx_string_put(mm->mlx, mm->win_help, 10, 110, WHITE, "Reset - Backspace");
	mlx_string_put(mm->mlx, mm->win_help, 10, 130, WHITE, "Change fractal - 1/2/3");
	mlx_string_put(mm->mlx, mm->win_help, 10, 150, WHITE, "Psyhodelic - P");
	mlx_string_put(mm->mlx, mm->win_help, 10, 170, WHITE, "Change colors - C");
	help_curr_frac(mm);
	mlx_string_put(mm->mlx, mm->win_help, 100, 220, YELLOW, "Fractals");
	mlx_string_put(mm->mlx, mm->win_help, 10, 240, WHITE, "1. Julia");
	mlx_string_put(mm->mlx, mm->win_help, 10, 260, WHITE, "2. Mandelbrot");
	mlx_string_put(mm->mlx, mm->win_help, 10, 280, WHITE, "3. Rhombus");
	mlx_string_put(mm->mlx, mm->win_help, 10, 300, WHITE, "4. Signal");
	mlx_string_put(mm->mlx, mm->win_help, 10, 320, WHITE, "5. Shell");
	mlx_string_put(mm->mlx, mm->win_help, 10, 340, WHITE, "6. 6");
	mlx_string_put(mm->mlx, mm->win_help, 10, 360, WHITE, "7. 7");
	mlx_string_put(mm->mlx, mm->win_help, 10, 380, WHITE, "8. 8");
	mlx_string_put(mm->mlx, mm->win_help, 10, 400, WHITE, "9. Web");
	mlx_string_put(mm->mlx, mm->win_help, 10, 420, WHITE, "10. Rings");
}

void	help_curr_frac(t_main *mm)
{
	if (mm->id == 1)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Julia");
	if (mm->id == 2)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Mandelbrot");
	if (mm->id == 3)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Rhombus");
	if (mm->id == 4)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Signal");
	if (mm->id == 5)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Shell");
	if (mm->id == 9)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Web");
	if (mm->id == 10)
		mlx_string_put(mm->mlx, mm->win_help, 10, 200, GREEN, "Current: Rings");
}

void	fract_list(char *error)
{
	ft_putendl(error);
	ft_putendl("\x1b[1;33m*** Fract'ols ***\x1b[0m");
	ft_putendl("\x1b[1;32mJulia\x1b[0m");
	ft_putendl("\x1b[1;32mMandelbrot\x1b[0m");
	ft_putendl("\x1b[1;32mRhombus\x1b[0m");
	ft_putendl("\x1b[1;32mSignal\x1b[0m");
	ft_putendl("\x1b[1;32mShell\x1b[0m");
	ft_putendl("\x1b[1;32m6\x1b[0m");
	ft_putendl("\x1b[1;32m7\x1b[0m");
	ft_putendl("\x1b[1;32m8\x1b[0m");
	ft_putendl("\x1b[1;32mWeb\x1b[0m");
	ft_putendl("\x1b[1;32mRings\x1b[0m");
	ft_putendl("\x1b[1;33m*****************\x1b[0m");
	die("\x1b[1;33mStoping...\x1b[0m");
}
