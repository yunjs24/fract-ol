/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:10:18 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/19 23:03:13 by junsyun          ###   ########.fr       */
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

/*for checking input arguments*/
int		check_input(t_fractol *f, int ac, char *av[]);
void	print_manual(const char *msg);

void	fractol_draw(t_fractol *f);


/* init_tools */
void	image_init(t_fractol *f);
void	fractol_init(t_fractol *f);
int		fractol_mlx_init(t_fractol *f);


/* Event Hooks*/
int		key_hook(int keycode, t_fractol *f);
void	mouse_hook(int keycode, t_fractol *f);
#endif