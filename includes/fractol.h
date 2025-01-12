/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:01:02 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/12 11:56:29 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 100
# define ZOOM_FACTOR 1.1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	double	min_real;
	double	max_real;
	double	min_imaginary;
	double	max_imaginary;

	double	zoom;
	double	offset_x;
	double	offset_y;
}			t_fractol;

void		init_fractol(t_fractol *fractol);
int			mandelbrot(double real, double imaginary);
void		render_mandelbrot(t_fractol *fractol);
void		put_pixel(t_data *img, int x, int y, int color);
int			handle_keypress(int keycode, t_fractol *fractol);
int			mouse_scroll(int button, int x, int y, t_fractol *fractol);
// int			close_window(void *param);
// int			mouse_scroll(int button, int x, int y, t_fractol *fractol);
// int			key_press(int keycode, t_fractol *fractol);
int			get_color(int iteration);
void		exit_wit_errors(char *message);
void		ft_putstr(char *s);
int			ft_strncmp(const char *first, const char *second, size_t length);

#endif
