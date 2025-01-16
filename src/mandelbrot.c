/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:52:09 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/16 11:51:31 by ayaarab          ###   ########.fr       */
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
	int		iter;
	int		x;
	int		y;
	double	real;
	double	imaginary;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			real = fractol->min_real + (double)x / WIN_WIDTH
				* (fractol->max_real - fractol->min_real);
			imaginary = fractol->max_imaginary - (double)y / WIN_HEIGHT
				* (fractol->max_imaginary - fractol->min_imaginary);
			iter = mandelbrot(real, imaginary);
			put_pixel(&fractol->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
