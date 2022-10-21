/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:00:30 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/22 06:37:00 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		tmp;
	int			i;

	i = 0;
	z.x = c.x;
	z.y = c.y;
	while (i < N && (z.x * z.x) + (z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + f->julia.x;
		z.y = (2 * tmp * z.y) + f->julia.y;
		i++;
	}
	f->iter_cnt = i;
}


void	fractol_mandelbrot(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		t_x;
	double		t_y;
	double		t_xy;
	int			i;

	z.x = c.x;
	z.y = c.y;
	i = 0;
	while (i < N)
	{
		t_xy = 2 * z.x * z.y;
		t_x = z.x * z.x;
		t_y = z.y * z.y;
		if (t_x + t_y >= 4)
			break ;
		t_x -= t_y;
		z.x = t_x + c.x;
		z.y = t_xy + c.y;
		i++;
	}
}

void	fractol_burningship(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		t_x;
	double		t_y;
	double		t_xy;
	int			i;

	z.x = c.x;
	z.y = c.y;
	i = 0;
	while (i < N)
	{
		t_xy = 2 * z.x * z.y;
		t_x = z.x * z.x;
		t_y = z.y * z.y;
		if (t_x + t_y >= 4)
			break ;
		t_x -= t_y;
		z.x = t_x + c.x;
		z.y = -t_xy + c.y;
		i++;
	}
}