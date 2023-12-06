/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/12/06 12:11:34 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_args(const char *s, va_list *args, int *l, int pos)
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
		ft_putstr(va_arg(*args, char *), l);
	else
		ft_putchar(s[pos], l);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			ft_printf_args(s, &args, &ret, ++i);
		else if (s[i] != '%')
			ft_putchar(s[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
// #include <stdio.h>

// int main() {
// 	char *s=NULL;
// 	ft_printf("%d\n", ft_printf("%d %x %X %p %s %c %u %i", 2147483648,-1,-1, NULL, s, '1', -2147483647));
// 	//ft_printf("%s\n", NULL);
// 	ft_printf("%s\n", NULL);
// }