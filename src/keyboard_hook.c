/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:40:53 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/25 04:15:35 by junsyun          ###   ########.fr       */
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
