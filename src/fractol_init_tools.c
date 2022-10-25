/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:21:22 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 01:16:18 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_init(t_fractol *f)
{
	f->color = 0x00008db8;
	f->zoom_ratio = 0.03;
	if (f->fp == fractol_mandelbrot)
	{
		f->x_max = 1.5;
		f->x_min = -2.5;
		f->y_max = 2.0;
		f->y_min = -2.0;
	}
	else
	{
		f->x_max = 2.0;
		f->x_min = -2.0;
		f->y_max = 2.0;
		f->y_min = -2.0;
	}
}

int	fractol_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->window = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, f->title);
	if (!f->window)
		return (0);
	f->img = (t_image *)malloc(sizeof(t_image));
	if (!f->img)
		return (0);
	fractol_init(f);
	mlx_key_hook(f->window, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	return (1);
}

/**todo : image error message**/
void	image_init(t_fractol *f)
{
	f->img->ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img->ptr)
		exit(1);
	f->img->buff = (int *)mlx_get_data_addr(f->img->ptr, \
		&f->img->bits_per_pixel, &f->img->line_length, &f->img->endian);
	if (!f->img->buff)
		exit(1);
}
