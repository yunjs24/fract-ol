/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:30:38 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/19 21:30:34 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_manual(const char *msg)
{
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
	ft_putstr_fd("\tchange color : [LEFT_Button]\n", STDOUT_FILENO);
}

int		check_input(t_fractol *f, int ac, char *av[])
{
	f->set = 0;
	if (ac >= 2)
	{
		f->title = av[1];
		if (!ft_strcmp(f->title, "mandelbrot"))
		{
			f->set = 1;
		}
		else if (!ft_strcmp(f->title, "julia") && ac == 4)
		{
			f->set = 1;
			f->julia.x = ft_atof(av[2]);
			f->julia.y = ft_atof(av[3]);
		}
		else if (!ft_strcmp(f->title, "burningship"))
		{
			f->set = 3;
		}
	}
	else
		print_manual(NULL);
	return (f->set)
}
