/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:07:00 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/06 18:54:29 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_fractol	f;

	if (check_input(&f, ac, av))
	{
		if (!mlx_init(&f))
			err_exit("\n[error] : mlx_init() fail!\n");
		image_init(&f);
		fractol_draw(&f);
		mlx_loop(f.mlx);
	}
	return (0);
}
