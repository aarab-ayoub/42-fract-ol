/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:51:52 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/10 20:05:40 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->min_real = -2;
	fractol->max_real = 2;
	fractol->min_imaginary = -2;
	fractol->min_imaginary = 2;
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		exit_wit_errors("MiniLibX initialization failed");
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIN_HEIGHT, WIN_WIDTH,
			"madelbrot");
	if (!fractol->win_ptr)
		exit_wit_errors("Windows creation failed");
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	if (!fractol->img.img)
		exit_wit_errors("image initializeed failed");
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc != 2 || ft_strncmp(argv[1], "mandelbrot", 9)))
	{
		ft_putstr("Usage: ./fractol mandelbrot\n ./fractol  julia [width] [height]\n");
		return (0);
	}
	init_fractol(&fractol);
	if (ft_strncmp(argv[1], "mandelbrot", 9))
		render_mandelbrot(&fractol);
	// else if (ft_strncmp(argv[1], "julia", 5))
	// rendring #TODO
	mlx_key_hook(fractol.win_ptr, handle_keypress, &fractol);
	mlx_mouse_hook(fractol.win_ptr, handle_mouse, &fractol);
	mlx_loop(fractol.mlx_ptr);
	return (0);
}
