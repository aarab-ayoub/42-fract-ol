/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:57:28 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/18 14:49:13 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double real, double imaginary)
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
		z_imaginary = -fabs(2 * z_real * z_imaginary) + imaginary;
		z_real = z_real2 - z_imaginary2 + real;
		iter++;
	}
	return (iter);
}

void	render_burning_ship(t_fractol *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imaginary;
	int		iter;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			real = fractol->min_real + (double)x / WIN_WIDTH
				* (fractol->max_real - fractol->min_real) + fractol->offset_x;
			imaginary = fractol->max_im - (double)y / WIN_HEIGHT
				* (fractol->max_im - fractol->min_im) + fractol->offset_y;
			iter = burning_ship(real, imaginary) + fractol->offset_y;
			put_pixel(&fractol->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
