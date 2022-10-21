/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:10:18 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/22 07:06:33 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "types.h"

# define WIN_WIDTH	1600
# define WIN_HEIGHT	900
# define N			10

/*for checking input arguments*/
int		check_input(t_fractol *f, int ac, char *av[]);
void	print_manual(const char *msg);

/* init_tools */
void	image_init(t_fractol *f);
void	fractol_init(t_fractol *f);
int		fractol_mlx_init(t_fractol *f);
int		set_color_pixel(t_fractol *f, int x, int y);

/* draw and complex sets*/
void	fractol_draw(t_fractol *f);
void	fractol_julia(t_fractol *f);
void	fractol_mandelbrot(t_complex c, t_fractol *f);
void	fractol_burningship(t_complex c, t_fractol *f);

/* Event Hooks*/
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int button, t_fractol *f, int x, int y);
#endif
