/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:39:06 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/11 13:00:32 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// void	render(t_fractol *fractol)
// {
// 	mandelbrot(fractol);
// 	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img, 0,
// 		0);
// }

// // Calculate the number of iterations for a point in the Mandelbrot set
// int	mandelbrot(double real, double imaginary)
// {
// 	double	z_real;
// 	double	z_imaginary;
// 	double	z_real2;
// 	double	z_imaginary2;
// 	int		iter;

// 	z_real = 0;
// 	z_imaginary = 0;
// 	z_real2 = 0;
// 	z_imaginary2 = 0;
// 	iter = 0;
// 	while (iter < MAX_ITER)
// 	{
// 		z_real2 = z_real * z_real;
// 		z_imaginary2 = z_imaginary * z_imaginary;
// 		if (z_real2 + z_imaginary2 > 4.0) // Escape condition
// 			break ;
// 		z_imaginary = 2 * z_real * z_imaginary + imaginary;
// 		z_real = z_real2 - z_imaginary2 + real;
// 		iter++;
// 	}
// 	return (iter);
// }

// // Render the Mandelbrot set
// void	render_mandelbrot(t_fractol *fractol)
// {
// 	int x, y;
// 	double real, imaginary;
// 	int iter;

// 	for (y = 0; y < WIN_HEIGHT; y++)
// 	{
// 		for (x = 0; x < WIN_WIDTH; x++)
// 		{
// 			// Map pixel coordinates to the complex plane
// 			real = fractol->min_real + (double)x / WIN_WIDTH
// 				* (fractol->max_real - fractol->min_real);
// 			imaginary = fractol->max_imaginary - (double)y / WIN_HEIGHT
// 				* (fractol->max_imaginary - fractol->min_imaginary);

// 			// Calculate the number of iterations
// 			iter = mandelbrot(real, imaginary);

// 			// Draw the pixel
// 			put_pixel(&fractol->img, x, y, get_color(iter));
// 		}
// 	}
// 	// Display the image in the window
// 	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
// 		fractol->img.img, 0, 0);
// }