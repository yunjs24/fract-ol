/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:07:00 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/27 23:21:46 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_fractol	f;

	if (check_input(&f, ac, av))
	{
		if (!fractol_mlx_init(&f))
		{
			print_manual("\n[error] : mlx_init() fail!\n");
			exit(1);
		}
		image_init(&f);
		fractol_draw(&f);
		mlx_loop(f.mlx);
	}
	return (0);
}
