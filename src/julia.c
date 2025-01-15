#include "fractol.h"

int julia(double real, double imaginary, double c_real, double c_imaginary)
{
    double z_real = real;
    double z_imaginary = imaginary;
    double z_real2 = 0;
    double z_imaginary2 = 0;
    int iter = 0;

    while (iter < MAX_ITER)
    {
        z_real2 = z_real * z_real;
        z_imaginary2 = z_imaginary * z_imaginary;
        if (z_real2 + z_imaginary2 > 4.0) // Escape condition (|z| > 2)
            break;
        z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
        z_real = z_real2 - z_imaginary2 + c_real;
        iter++;
    }
    return iter;
}

void render_julia(t_fractol *fractol, double c_real, double c_imaginary)
{
    int x = 0;
    int y = 0;

    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            // Map pixel coordinates to the complex plane
            double real = fractol->min_real + (double)x / WIN_WIDTH * (fractol->max_real - fractol->min_real);
            double imaginary = fractol->max_imaginary - (double)y / WIN_HEIGHT * (fractol->max_imaginary - fractol->min_imaginary);

            // Calculate the number of iterations
            int iter = julia(real, imaginary, c_real, c_imaginary);

            // Draw the pixel
            put_pixel(&fractol->img, x, y, get_color(iter));

            x++;
        }
        y++;
    }
    // Display the image in the window
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img.img, 0, 0);
}