/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:02:03 by dirony            #+#    #+#             */
/*   Updated: 2021/11/24 21:26:10 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char ch, t_flag *flag)
{
	write(1, &ch, 1);
	flag->counter++;
}

void	ft_putstr(char *str, t_flag *flag)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		if (flag->point && flag->accuracy < len && flag->type == 's')
			len = flag->accuracy;
		write(1, str, len);
		flag->counter += len;
	}
}

int	ft_putnbr(long long n, t_flag *flag)
{
	char	result[18];
	int		i;

	if (flag->point && flag->accuracy == 0 && n == 0)
		return (0);
	i = 1;
	if (n == 0)
		ft_putchar('0', flag);
	if (n < 0)
	{
		n = -n;
		if (!flag->zero && !flag->point)
			ft_putchar('-', flag);
	}
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i)
		ft_putchar(result[i--], flag);
	return (0);
}

char	*ft_strchr(const char *s, int ch)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return (&str[i]);
		i++;
	}
	if ((char)ch == '\0')
		return (&str[i]);
	return (NULL);
}
