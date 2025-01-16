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
		if (z_real2 + z_imaginary2 > 4.0) // Escape condition (|z| > 2)
			break ;
		z_imaginary = -fabs(2 * z_real * z_imaginary) + imaginary;
		z_real = z_real2 - z_imaginary2 + real;
		iter++;
	}
	return (iter);
}

void	render_burning_ship(t_fractol *fractol)
{
	int x = 0;
	int y = 0;

	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			// Map pixel coordinates to the complex plane
			double real = fractol->min_real + (double)x / WIN_WIDTH
				* (fractol->max_real - fractol->min_real);
			double imaginary = fractol->max_imaginary - (double)y / WIN_HEIGHT
				* (fractol->max_imaginary - fractol->min_imaginary);

			// Calculate the number of iterations
			int iter = burning_ship(real, imaginary);

			// Draw the pixel
			put_pixel(&fractol->img, x, y, get_color(iter));

			x++;
		}
		y++;
	}
	// Display the image in the window
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}