/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:27:43 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/10 21:11:04 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		exit(0);
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;

	mouse_x = fractol->min_real + (x * (fractol->max_real - fractol->min_real)
			/ WIN_WIDTH);
	mouse_y = fractol->min_imaginary + (y * (fractol->max_imaginary
				- fractol->min_imaginary) / WIN_HEIGHT);
	zoom = 0.9;
	if (button == 4)
	{
		fractol->min_real = mouse_x + (fractol->min_real - mouse_x) * zoom;
		fractol->max_real = mouse_x + (fractol->max_real - mouse_x) * zoom;
		fractol->min_imaginary = mouse_y + (fractol->min_imaginary - mouse_y)
			* zoom;
		fractol->max_imaginary = mouse_y + (fractol->max_imaginary - mouse_y)
			* zoom;
	}
	else if (button == 5)
	{
		fractol->min_real = mouse_x + (fractol->min_real - mouse_x) / zoom;
		fractol->max_real = mouse_x + (fractol->max_real - mouse_x) / zoom;
		fractol->min_imaginary = mouse_y + (fractol->min_imaginary - mouse_y)
			/ zoom;
		fractol->max_imaginary = mouse_y + (fractol->max_imaginary - mouse_y)
			/ zoom;
	}
	render_mandelbrot(fractol);
	return (0);
}
