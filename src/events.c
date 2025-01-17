/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:27:43 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/17 20:05:14 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractol *fractol)
{
	if (ft_strncmp(fractol->f_type, "mandelbrot", 10) == 0)
		render_mandelbrot(fractol);
	else if (ft_strncmp(fractol->f_type, "julia", 5) == 0)
		render_julia(fractol, fractol->c_real, fractol->c_imaginary);
}

int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		exit(0);
	}
	if (keycode == 123)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (keycode == 126)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (keycode == 124)
		fractol->offset_x += 0.1 / fractol->zoom;
	else if (keycode == 125)
		fractol->offset_y += 0.1 / fractol->zoom;
	render_fractal(fractol);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	mouse_x = fractol->min_real + ((double)x / WIN_WIDTH) * (fractol->max_real
			- fractol->min_real);
	mouse_y = fractol->max_im - ((double)y / WIN_HEIGHT) * (fractol->max_im
			- fractol->min_im);
	if (button == 4)
	{
		zoom_factor = ZOOM_FACTOR;
		fractol->zoom *= zoom_factor;
	}
	else if (button == 5)
	{
		zoom_factor = 1.0 / ZOOM_FACTOR;
		fractol->zoom /= ZOOM_FACTOR;
	}
	fractol->min_real = mouse_x + (fractol->min_real - mouse_x) * zoom_factor;
	fractol->max_real = mouse_x + (fractol->max_real - mouse_x) * zoom_factor;
	fractol->min_im = mouse_y + (fractol->min_im - mouse_y) * zoom_factor;
	fractol->max_im = mouse_y + (fractol->max_im - mouse_y) * zoom_factor;
	render_fractal(fractol);
	return (0);
}
