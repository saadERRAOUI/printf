/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/18 16:22:12 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_args(const char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

static void	ft_printf_args(char *s, va_list *args, int *l, int pos)
{
	if (s[pos] == 'c')
		ft_putchar(va_arg(*args, int), l);
	else if (s[pos] == 'i' || s[pos] == 'd')
		ft_putnbr(va_arg(*args, int), l);
	else if (s[pos] == 'u')
		ft_print_base(va_arg(*args, unsigned int), "0123456789", 10, l);
	else if (s[pos] == 'x')
		ft_print_base(va_arg(*args, unsigned int), "0123456789abcdef", 16, l);
	else if (s[pos] == 'X')
		ft_print_base(va_arg(*args, unsigned int), "0123456789ABCDEF", 16, l);
	else if (s[pos] == 'p')
	{
		ft_putstr("0x", l);
		ft_print_base(va_arg(*args, unsigned long), "0123456789abcdef", 16, l);
	}
	else if (s[pos] == 's')
	{
		if (!ft_putstr(va_arg(*args, char *), l))
			ft_putstr("(null)", l);
	}
	else
		ft_putchar(s[pos], l);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!count_args(s))
	{
		ft_putstr((char *)s, &len);
		return (len);
	}
	va_start(args, s);
	while (s[i])
	{
		if (!ft_isprint(s[i]))
			return (-1);
		if (s[i] == '%' && s[i + 1])
			ft_printf_args((char *)s, &args, &len, ++i);
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
