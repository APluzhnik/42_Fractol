/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 12:40:56 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_main	*mm;

	if (ac != 2)
		die("Usage: ./fractol <Fractal_name>");
	mm = ft_memalloc(sizeof(t_main));
	mm->name = av[1];
	if (!(mm->id = is_fractal(mm)))
		die("Error: name is incorrect");
	mm->mlx = mlx_init();
	mm->win = mlx_new_window(mm->mlx, WIN_W, WIN_H, av[1]); // "Fractol"
	mm->img.ptr = mlx_new_image(mm->mlx, WIN_W, WIN_H);
	mm->img.data = (int*)mlx_get_data_addr(mm->img.ptr, &mm->img.bpp, &mm->img.size_line, &mm->img.endian);
	init(mm);
	render(mm);
	mlx_put_image_to_window(mm->mlx, mm->win, mm->img.ptr, 0, 0);
	mlx_hook(mm->win, 2, 0, mlx_key_events, mm);
	mlx_hook(mm->win, 4, 0, mlx_mouse_events, mm);
	mlx_hook(mm->win, 17, 0, close_ok, mm);
	mlx_loop(mm->mlx);
	return (0);
}

int		close_ok(t_main *mm)
{
	mlx_destroy_image(mm->mlx, mm->img.ptr);
	free(mm);
	exit(EXIT_SUCCESS);
}

int		is_fractal(t_main *mm)
{
	if (!(ft_strcmp(mm->name, "Julia")))
		return (1);
	if (!(ft_strcmp(mm->name, "Mandelbrot")))
		return (2);
	return (0);
}
