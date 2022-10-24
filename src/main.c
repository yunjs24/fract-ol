/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:07:00 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/25 04:51:20 by junsyun          ###   ########.fr       */
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
		// ft_putstr_fd("testtest\n", 1);
		image_init(&f);
		fractol_draw(&f);
		mlx_loop(f.mlx);
	}
	return (0);
}
