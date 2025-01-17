/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:51:52 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/17 21:47:58 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->min_real = -2.0;
	fractol->max_real = 2.0;
	fractol->min_im = -2;
	fractol->max_im = 2;
	fractol->max_iter = 100;
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
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
}

static void	usage_messages(void)
{
	ft_putstr("/fractol burning_ship\n");
}

static int	handel_argument(int argc, char *argv[], t_fractol *fractol)
{
	if (argc < 2)
	{
		usage_messages();
		return (0);
	}
	fractol->f_type = argv[1];
	if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
		render_burning_ship(fractol);
	else
	{
		usage_messages();
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	init_fractol(&fractol);
	if (!handel_argument(argc, argv, &fractol))
		return (0);
	mlx_key_hook(fractol.win_ptr, handle_keypress, &fractol);
	mlx_mouse_hook(fractol.win_ptr, mouse_scroll, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx_ptr);
	return (0);
}
