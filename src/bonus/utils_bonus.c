/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:39:16 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/15 17:46:52 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// int	get_color(int iteration)
// {
//     if (iteration == MAX_ITER)
//         return (0x000000);

//     double t = (double)iteration / MAX_ITER;
//     int r = (int)(9 * (1 - t) * t * t * t * 255);
//     int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

//     return (r << 16 | g << 8 | b);
// }
int get_color(int iteration)
{
    if (iteration == MAX_ITER)
        return (0x000000); 
    double t = (double)iteration / MAX_ITER;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255); 
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); 

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
