/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:01:02 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/10 17:02:00 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 100

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
}			t_fractol;

#endif
