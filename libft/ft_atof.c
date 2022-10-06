/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:03:23 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/06 18:04:31 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		len;
	int		m_flag;
	int		i;
	double	ret;
	double	temp;

	i = 0;
	m_flag = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		m_flag = -1;
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
	return (m_flag * (ret + temp));
}
