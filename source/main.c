/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/13 19:14:45 by apluzhni         ###   ########.fr       */
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
	mm->img.data = (int*)mlx_get_data_addr(mm->img.ptr, &mm->img.bpp, &mm->img.size_line, &mm->img.endian);
	init(mm);
	make(mm);
	system("afplay music/sound.mp3&");
	mlx_hook(mm->win, 2, 0, mlx_key_events, mm);
	mlx_hook(mm->win, 4, 0, mlx_mouse_events, mm);
	mlx_hook(mm->win, 6, 0, mlx_mouse_move, mm);
	mlx_hook(mm->win, 17, 0, close_ok, mm);
	mlx_loop_hook(mm->mlx, effects, mm);
	mlx_loop(mm->mlx);
	return (0);
}

int		close_ok(t_main *mm)
{
	system("killall afplay");
	mlx_destroy_image(mm->mlx, mm->img.ptr);
	free(mm);
	// system("leaks -q fractol");
	exit(EXIT_SUCCESS);
}

/*
ID: 6 7 8 || tbahlai: 5 6 9 10 12 13 14 15
Color change by one
Music player separate

Norme
*/
