/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:21:22 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 01:16:05 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_draw(t_fractol *f)
{
	int		x;
	int		y;

	x = 0;
	image_init(f);
	while (x < WIN_WIDTH)
	{
		y = 0;
		f->c.x = f->x_min + x * ((f->x_max - f->x_min) / WIN_WIDTH);
		while (y < WIN_HEIGHT)
		{
			f->c.y = f->y_min + y * ((f->y_max - f->y_min) / WIN_HEIGHT);
			f->fp(f->c, f);
			set_color_pixel(f, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img->ptr, 0, 0);
	mlx_destroy_image(f->mlx, f->img->ptr);
}

void	set_color_pixel(t_fractol *f, int x, int y)
{
	int	pixel;
	int	color;

	color = 0;
	if (f->iter_cnt != ITER_MAX)
		color = 1;
	pixel = (y * WIN_WIDTH + x);
	f->img->buff[pixel] = ((f->iter_cnt * f->color) + 0x00F0F8FF) * color;
}
