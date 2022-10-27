/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:12:14 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/26 10:06:59 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_image
{
	void	*ptr;
	int		*buff;
	int		endian;
	int		line_length;
	int		bits_per_pixel;

}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		*img;
	char		*title;
	void		(*fp)(t_complex c, struct s_fractol *f);
	t_complex	c;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom_ratio;
	int			color;
	t_complex	julia;
	int			iter_cnt;
}				t_fractol;

#endif