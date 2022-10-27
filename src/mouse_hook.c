/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:03:11 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 11:04:04 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycode.h"

static void	zoom_in(t_fractol *f, double x, double y)
{
	double	xx;
	double	yy;
	double	ratio;

	ratio = 0.8;
	xx = (((double)x / WIN_WIDTH) * (f->x_max - f->x_min)) + f->x_min;
	yy = (((double)y / WIN_HEIGHT) * (f->y_max - f->y_min)) + f->y_min;
	f->x_min = xx + ((f->x_min - xx) * ratio);
	f->y_min = yy + ((f->y_min - yy) * ratio);
	f->y_max = yy + ((f->y_max - yy) * ratio);
	f->x_max = xx + ((f->x_max - xx) * ratio);
}

static void	zoom_out(t_fractol *f, double x, double y)
{
	double	xx;
	double	yy;
	double	ratio;

	ratio = 1.2;
	xx = (((double)x / WIN_WIDTH) * (f->x_max - f->x_min)) + f->x_min;
	yy = (((double)y / WIN_HEIGHT) * (f->y_max - f->y_min)) + f->y_min;
	f->x_min = xx + ((f->x_min - xx) * ratio);
	f->y_min = yy + ((f->y_min - yy) * ratio);
	f->y_max = yy + ((f->y_max - yy) * ratio);
	f->x_max = xx + ((f->x_max - xx) * ratio);
}

static void	change_color(t_fractol *f)
{
	f->color += 525456;
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == M_SCROLL_UP)
	{
		zoom_in(f, (double)x, (double)y);
		fractol_draw(f);
	}
	else if (button == M_SCROLL_DOWN)
	{
		zoom_out(f, (double)x, (double)y);
		fractol_draw(f);
	}
	else if (button == M_LEFT_BUTTON)
	{
		change_color(f);
		fractol_draw(f);
	}
	return (1);
}
