/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:48:48 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/16 13:02:33 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double real, double imaginary, double c_real, double c_imaginary)
{
	double	z_real;
	double	z_imaginary;
	double	z_real2;
	double	z_imaginary2;
	int		iter;

	z_real = real;
	z_imaginary = imaginary;
	z_real2 = 0;
	z_imaginary2 = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		z_real2 = z_real * z_real;
		z_imaginary2 = z_imaginary * z_imaginary;
		if (z_real2 + z_imaginary2 > 4.0)
			break ;
		z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
		z_real = z_real2 - z_imaginary2 + c_real;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fractol *fractol, double c_real, double c_imaginary)
{
	int		x;
	int		y;
	double	real;
	double	imaginary;
	int		iter;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			real = fractol->min_real + (double)x / WIN_WIDTH
				* (fractol->max_real - fractol->min_real) + fractol->offset_x;
			imaginary = fractol->max_imaginary - (double)y / WIN_HEIGHT
				* (fractol->max_imaginary - fractol->min_imaginary)
				+ fractol->offset_y;
			iter = julia(real, imaginary, c_real, c_imaginary);
			put_pixel(&fractol->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
