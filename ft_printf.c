/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/12 17:48:12 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

int count_args(const char *s)
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	number = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	if (number <= 9)
		ft_putchar_fd(number + '0', fd);
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd(number % 10 + '0', fd);
	}
}

void    ft_puthex_upper_fd(int n, int fd)
{
    unsigned int number;

    number = (unsigned int)n;
    if(number <= 16)
    {
        if (number < 10)
            ft_putchar_fd(number + '0', fd);   
        else
            ft_putchar_fd(number + '7', fd);
    }
    else {
        ft_puthex_upper_fd(number / 16, fd);
        if ((number % 16) < 10)
            ft_putchar_fd((number % 16) + '0', fd);   
        else
            ft_putchar_fd((number % 16) + '7', fd);
    }
}


int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void    ft_puthex_fd(int n, int fd)
{
    unsigned int number;

    number = (unsigned int)n;
    if(number <= 16)
    {
        if (number < 10)
            ft_putchar_fd(number + '0', fd);   
        else
            ft_putchar_fd(ft_tolower(number + '7'), fd);
    }
    else {
        ft_puthex_fd(number / 16, fd);
        if ((number % 16) < 10)
            ft_putchar_fd((number % 16) + '0', fd);   
        else
            ft_putchar_fd(ft_tolower((number % 16) + '7'), fd);
    }
}

void    ft_putptr_fd(unsigned long number, int fd)
{
    if(number <= 16)
    {
        if (number < 10)
            ft_putchar_fd(number + '0', fd);   
        else
            ft_putchar_fd(number + '7', fd);
    }
    else {
        ft_puthex_upper_fd(number / 16, fd);
        if ((number % 16) < 10)
            ft_putchar_fd((number % 16) + '0', fd);   
        else
            ft_putchar_fd((number % 16) + '7', fd);
    }
}

int ft_printf(const char *s, ...)
{
	//Todo : Learn more about va_start, va_arg, va_copy and va_end
	//Todo : Return the number of arguments processed ?
	//Todo : Loop on the char on the param and check wether it is on of the conversions after the '%' char is found
	//Todo : Call specific method for each type of conversion {'%:done', 'c:done', 's:done', 'p:done', 'd:done', 'i:done', 'u', 'x:done', 'X:done'}
	char	conv_ident;
	int		i;
	va_list	args;
	size_t	len_s;

	if (!count_args(s))
	{
		ft_putstr_fd((char *)s, 1);
		return (0);
	}
	i = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%' && s[i + 1])
		{
			//Todo : pass this logic to another function due to norminette limit break - 25 lines per function
			conv_ident = s[i + 1];
			//Todo : calls a function that distinguish which of conversion we have
			if (conv_ident == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (conv_ident == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (conv_ident == '%')
				ft_putchar_fd('%', 1);
			else if (conv_ident == 'i' || conv_ident == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (conv_ident == 'x')
				ft_puthex_fd(va_arg(args, unsigned int), 1);
			else if (conv_ident == 'X')
				ft_puthex_upper_fd(va_arg(args, unsigned int), 1);
			else if (conv_ident == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_putptr_fd(va_arg(args, unsigned long), 1);
			}
			else
				ft_putchar_fd(s[i + 1], 1);
			i++;
		}
		else {
			ft_putchar_fd(s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count_args(args));
}

int main()
{
	char *p;
	int count = ft_printf("-----%p \n", 0xFFFFFFFF);
	printf("%d\n", 0xFF);
	return (0);
}