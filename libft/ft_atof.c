/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:03:23 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/25 04:13:43 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		len;
	int		sign;
	int		i;
	double	ret;
	double	temp;

	i = 0;
	sign = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	ret = ft_atol(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	temp = ft_atol(str + i);
	i = len - i;
	while (i--)
		temp /= 10;
	return (sign * (ret + temp));
}
