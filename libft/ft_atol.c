#include "libft.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	ret;
	int		m_flag;

	i = 0;
	m_flag = 0;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || \
	str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		m_flag = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (m_flag != 0)
		ret *= -1;
	return (ret);
}