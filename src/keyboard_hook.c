/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:40:53 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 01:16:42 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycode.h"

int	key_move(int keycode, t_fractol *f)
{
	if (keycode == KEY_UP)
	{
		f->y_min -= f->zoom_ratio;
		f->y_max -= f->zoom_ratio;
		fractol_draw(f);
	}
	else if (keycode == KEY_DOWN)
	{
		f->y_min += f->zoom_ratio;
		f->y_max += f->zoom_ratio;
		fractol_draw(f);
	}
	else if (keycode == KEY_LEFT)
	{
		f->x_min -= f->zoom_ratio;
		f->x_max -= f->zoom_ratio;
		fractol_draw(f);
	}
	else if (keycode == KEY_RIGHT)
	{
		f->x_min += f->zoom_ratio;
		f->x_max += f->zoom_ratio;
		fractol_draw(f);
	}
	return (1);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		ft_putstr_fd("EXIT by ESC!\n", 1);
		free(f->img);
		exit(0);
	}
	else
		key_move(keycode, f);
	return (1);
}
