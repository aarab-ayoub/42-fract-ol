/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:27:43 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/10 19:57:42 by ayaarab          ###   ########.fr       */
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

int	handle_mouse(int button, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->min_real *= 0.9;
		fractol->max_real *= 0.9;
		fractol->min_imaginary *= 0.9;
		fractol->max_imaginary *= 0.9;
	}
	else if (button == 5)
	{
		fractol->min_real *= 1.1;
		fractol->max_real *= 1.1;
		fractol->min_imaginary *= 1.1;
		fractol->max_imaginary *= 1.1;
	}
	render_mandelbrot(fractol);
	return (0);
}
