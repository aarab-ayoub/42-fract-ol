/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:51:52 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/10 16:59:29 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void init_fractol(t_fractol *fractol)
{
	
}
int	main(int argc, char *argv[])
{
	if ((argc != 2 && ft_strncmp(argv[1], "madelbrot", 9)) || (argc != 4
			&& ft_strncmp(argv[1], "julia", 5)))
	{
		ft_putstr("Usage: ./fractol [madelbrot/julia] [width] [height]\n");
		return (0);
	}
	else
	{
		t_fractol fractol;
		init_fractol(&fractol);
	}
	
}
