/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:39:16 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/18 12:58:14 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == MAX_ITER)
		return (0x000000);
	t = (double)iteration / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r * 65536 + g * 256 + b);
}

void	exit_wit_errors(char *message)
{
	ft_putstr(message);
	exit(1);
}

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (i < length && (first[i] != '\0' || second[i] != '\0'))
	{
		if ((unsigned char)first[i] != (unsigned char)second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}
