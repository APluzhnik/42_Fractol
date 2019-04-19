/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/17 16:07:01 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_main	*mm;

	if (ac != 2)
		fract_list("\x1b[1;31mUsage: ./fractol <Fractal_name>\x1b[0m");
	mm = ft_memalloc(sizeof(t_main));
	mm->name = av[1];
	if (!(mm->id = is_fractal(mm)))
		fract_list("\x1b[1;31mError: name is incorrect\x1b[0m");
	mm->mlx = mlx_init();
	mm->win = mlx_new_window(mm->mlx, WIN_W, WIN_H, "Fract'ol");
	mm->img.ptr = mlx_new_image(mm->mlx, WIN_W, WIN_H);
	mm->img.data = (int*)mlx_get_data_addr(mm->img.ptr, &mm->img.bpp,
	&mm->img.size_line, &mm->img.endian);
	init(mm);
	threading(mm);
	mlx_hook(mm->win, 2, 0, mlx_key_events, mm);
	mlx_hook(mm->win, 4, 0, mlx_mouse_events, mm);
	mlx_hook(mm->win, 6, 0, mlx_mouse_move, mm);
	mlx_hook(mm->win, 17, 0, close_ok, mm);
	mlx_loop_hook(mm->mlx, effects, mm);
	mlx_loop(mm->mlx);
	return (0);
}

int		is_fractal(t_main *mm)
{
	if (!(ft_strcmp(mm->name, "Julia")))
		return (1);
	if (!(ft_strcmp(mm->name, "Mandelbrot")))
		return (2);
	if (!(ft_strcmp(mm->name, "Rhombus")))
		return (3);
	if (!(ft_strcmp(mm->name, "Signal")))
		return (4);
	if (!(ft_strcmp(mm->name, "Shell")))
		return (5);
	if (!(ft_strcmp(mm->name, "Skull")))
		return (6);
	if (!(ft_strcmp(mm->name, "Onion")))
		return (7);
	if (!(ft_strcmp(mm->name, "Hazard")))
		return (8);
	if (!(ft_strcmp(mm->name, "Web")))
		return (9);
	if (!(ft_strcmp(mm->name, "Rings")))
		return (10);
	if (!(ft_strcmp(mm->name, "Smoke")))
		return (11);
	if (!(ft_strcmp(mm->name, "MilkyWay")))
		return (12);
	return (0);
}

int		close_ok(t_main *mm)
{
	system("killall afplay");
	mlx_destroy_image(mm->mlx, mm->img.ptr);
	free(mm);
	exit(EXIT_SUCCESS);
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
	ft_putendl("\x1b[1;32mSkull\x1b[0m");
	ft_putendl("\x1b[1;32mOnion\x1b[0m");
	ft_putendl("\x1b[1;32mHazard\x1b[0m");
	ft_putendl("\x1b[1;32mWeb\x1b[0m");
	ft_putendl("\x1b[1;32mRings\x1b[0m");
	ft_putendl("\x1b[1;32mSmoke\x1b[0m");
	ft_putendl("\x1b[1;32mMilkyWay\x1b[0m");
	ft_putendl("\x1b[1;33m*****************\x1b[0m");
	die("\x1b[1;33mStoping...\x1b[0m");
}
