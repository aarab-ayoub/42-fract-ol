/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:51:52 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/15 17:48:40 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->min_real = -2.0;
	fractol->max_real = 2.0;
	fractol->min_imaginary = -2;
	fractol->max_imaginary = 2;
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

#include "fractol.h"

int main(int argc, char *argv[])
{
    t_fractol fractol;

    if (argc < 2 || argc > 4)
    {
        ft_putstr("Usage: ./fractol <fractal_type> [c_real] [c_imaginary]\n");
        ft_putstr("Available fractals:\n");
        ft_putstr("  mandelbrot\n");
        ft_putstr("  julia <c_real> <c_imaginary>\n");
        ft_putstr("  burning_ship\n");
        return (0);
    }

    // Initialize fractal data
    init_fractol(&fractol);

    // Render the selected fractal
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
    {
        if (argc != 2)
        {
            ft_putstr("Usage: ./fractol mandelbrot\n");
            return (0);
        }
        render_mandelbrot(&fractol);
    }
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        if (argc != 4)
        {
            ft_putstr("Usage: ./fractol julia <c_real> <c_imaginary>\n");
            return (0);
        }
        double c_real = ft_atof(argv[2]); // Convert string to double
        double c_imaginary = ft_atof(argv[3]); // Convert string to double
        render_julia(&fractol, c_real, c_imaginary);
    }
    else if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
    {
        if (argc != 2)
        {
            ft_putstr("Usage: ./fractol burning_ship\n");
            return (0);
        }
        render_burning_ship(&fractol);
    }
    else
    {
        ft_putstr("Invalid fractal type. Available fractals:\n");
        ft_putstr("  mandelbrot\n");
        ft_putstr("  julia <c_real> <c_imaginary>\n");
        ft_putstr("  burning_ship\n");
        return (0);
    }

    // // Set up event hooks
    // mlx_key_hook(fractol.win_ptr, handle_keypress, &fractol);
    // mlx_mouse_hook(fractol.win_ptr, mouse_scroll, &fractol);

    // Start the MiniLibX event loop
    mlx_loop(fractol.mlx_ptr);

    return (0);
}
// mlx_key_hook(fractol.win_ptr, key_press, &fractol);
// mlx_mouse_hook(fractol.win_ptr, mouse_scroll, &fractol);
// // mlx_hook(fractol.win_ptr, 17, 0, close_window, &fractol);
