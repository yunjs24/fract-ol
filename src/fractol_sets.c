/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:00:30 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 01:18:39 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/types.h"

void	fractol_julia(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		t_xy;
	double		r;
	int			i;

	i = 0;
	z.x = c.x;
	z.y = c.y;
	while (i < ITER_MAX && (z.x * z.x) + (z.y * z.y) < 4)
	{
		z.x *= z.x;
		z.y *= z.y;
		r = z.x + z.y;
		if (r < 4)
			break ;
		t_xy = z.x;
		z.x = (z.x - z.y) + f->julia.x;
		z.y = (2 * t_xy * z.y) + f->julia.y;
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
	while (i < ITER_MAX)
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
	f->iter_cnt = i;
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
	while (i < ITER_MAX)
	{
		t_xy = 2 * z.x * z.y;
		t_x = z.x * z.x;
		t_y = z.y * z.y;
		if (t_x + t_y >= 4)
			break ;
		if (t_xy < 0)
			t_xy *= -1;
		z.x = t_x - t_y + c.x;
		z.y = t_xy + c.y;
		i++;
	}
	f->iter_cnt = i;
}
