/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:38:38 by dirony            #+#    #+#             */
/*   Updated: 2021/11/24 20:39:04 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*create_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (NULL == flag)
		return (NULL);
	flag->type = '\0';
	flag->counter = 0;
	flag->hash = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->point = 0;
	flag->accuracy = 0;
	flag->space = 0;
	flag->uppercase = 0;
	flag->width = 0;
	flag->zero = 0;
	return (flag);
}

void	reset_flag(t_flag *flag)
{
	flag->type = '\0';
	flag->hash = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->point = 0;
	flag->accuracy = 0;
	flag->space = 0;
	flag->uppercase = 0;
	flag->width = 0;
	flag->zero = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s;
	char	*temp;
	t_flag	*flag;

	s = (char *)str;
	va_start(args, str);
	flag = create_flag();
	while (*s)
	{
		temp = s;
		s = get_next_arg(s);
		print_orig_string(temp, s - temp, flag);
		s = get_flags(s, flag, args);
		s = parse_arg(s, args, flag);
		reset_flag(flag);
	}
	va_end(args);
	free(flag);
	return (flag->counter);
}
