/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:30:38 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 11:13:44 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_manual(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("USAGE : ./fractol <type>\n\n", STDOUT_FILENO);
	ft_putstr_fd("TYPES\n", STDOUT_FILENO);
	ft_putstr_fd("\t1. julia\n", STDOUT_FILENO);
	ft_putstr_fd("\t2. mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("\t3. burningship\n\n", STDOUT_FILENO);
	ft_putstr_fd("Keys\n", STDOUT_FILENO);
	ft_putstr_fd("\tMove : [← ↑ → ↓]\n", STDOUT_FILENO);
	ft_putstr_fd("\tExit : [ESC]\n\n", STDOUT_FILENO);
	ft_putstr_fd("\tMouse\n", STDOUT_FILENO);
	ft_putstr_fd("\tZoom : [Scroll]\n", STDOUT_FILENO);
	ft_putstr_fd("\tchange color : [Left_Button]\n", STDOUT_FILENO);
	return (1);
}
#include <stdio.h>
int	check_input(t_fractol *f, int ac, char *av[])
{
	f->fp = NULL;
	printf("ac : %d\n", ac);
	if (ac == 1)
		print_manual(NULL);
	else if (ac >= 2)
	{
		f->title = av[1];
		if (!ft_strcmp(f->title, "mandelbrot"))
		{
			f->fp = fractol_mandelbrot;
		}
		else if (!ft_strcmp(f->title, "julia") && ac == 4)
		{
			f->fp = fractol_julia;
			f->julia.x = ft_atof(av[2]);
			f->julia.y = ft_atof(av[3]);
		}
		else if (!ft_strcmp(f->title, "burningship"))
		{
			f->fp = fractol_burningship;
		}
		else
			print_manual(NULL);
	}
	if (f->fp)
		return (1);
	return (0);
}
