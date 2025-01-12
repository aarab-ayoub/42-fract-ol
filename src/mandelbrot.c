/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:52:09 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/12 11:56:25 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double real, double imaginary)
{
	double	z_real;
	double	z_imaginary;
	double	z_real2;
	double	z_imaginary2;
	int		iter;

	z_real = 0;
	z_imaginary = 0;
	z_real2 = 0;
	z_imaginary2 = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		z_real2 = z_real * z_real;
		z_imaginary2 = z_imaginary * z_imaginary;
		if (z_real2 + z_imaginary2 > 4.0)
			break ;
		z_imaginary = 2 * z_real * z_imaginary + imaginary;
		z_real = z_real2 - z_imaginary2 + real;
		iter++;
	}
	return (iter);
}

// Render the Mandelbrot set

// TODO
void	render_mandelbrot(t_fractol *fractol)
{
	int	iter;

	int x, y;
	double real, imaginary;
	for (y = 0; y < WIN_HEIGHT; y++)
	{
		for (x = 0; x < WIN_WIDTH; x++)
		{
			real = (x - WIN_WIDTH / 2.0) * (4.0 / (WIN_WIDTH * fractol->zoom))
				+ fractol->offset_x;
			imaginary = (y - WIN_HEIGHT / 2.0) * (4.0 / (WIN_HEIGHT
						* fractol->zoom)) + fractol->offset_y;
			iter = mandelbrot(real, imaginary);
			put_pixel(&fractol->img, x, y, get_color(iter));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
