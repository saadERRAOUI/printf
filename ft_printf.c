/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/17 23:03:01 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_args(const char *s)
{
	int count;
	int i;

	i = 0;
	count  = 0;
	while (s[i])
	{
		if(s[i] == '%' && s[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

static void	ft_printf_args(char *s, va_list *args, int *len, int pos)
{
	if (s[pos] == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s[pos] == 'i' || s[pos] == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else if (s[pos] == 'u')
		ft_print_base(va_arg(*args, unsigned int), "0123456789", 10, len);
	else if (s[pos] == 'x')
		ft_print_base(va_arg(*args, unsigned int), "0123456789abcdef", 16, len);
	else if (s[pos] == 'X')
		ft_print_base(va_arg(*args, unsigned int), "0123456789ABCDEF", 16, len);
	else if (s[pos] == 'p')
	{
		ft_putstr("0x", len);
		ft_print_base(va_arg(*args, unsigned long), "0123456789abcdef", 16, len);
	}
	else if (s[pos] == 's')
	{
		if (!ft_putstr(va_arg(*args, char *), len))
			ft_putstr("(null)", len);
	}
	else
		ft_putchar(s[pos], len);
}

int	ft_printf(const char *s, ...)
{
	//Todo : Learn more about va_start, va_arg, va_copy and va_end
	//Todo : Return the number of arguments processed ?
	//Todo : Loop on the char on the param and check wether it is on of the conversions after the '%' char is found
	//Todo : Call specific method for each type of conversion {'%:done', 'c:done', 's:done', 'p:done', 'd:done', 'i:done', 'u:done', 'x:done', 'X:done'}
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
		if(s[i] == '%' && s[i + 1])
			ft_printf_args((char *)s, &args, &len, ++i);
		else
			ft_putchar(s[i], &len);
		i++;	
	}
	va_end(args);
	return (len);
}