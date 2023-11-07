/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/08 00:04:19 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

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

	number = n;
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


int ft_printf(const char *s, ...)
{
	//Todo : Learn more about va_start, va_arg, va_copy and va_end
	//Todo : Return the number of arguments processed ?
	//Todo : Loop on the char on the param and check wether it is on of the conversions after the '%' char is found
	//Todo : Call specific method for each type of conversion {'%', 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'}
	char conv_ident;
	int i;
	va_list	args;
	va_start(args, s);
	size_t len_s;

	
	i = 0;
	len_s = strlen(s); //Todo : change to ft_strlen 
	while(s[i])
	{
		if(s[i] == '%' && s[i + 1])
		{
			conv_ident = s[i + 1];
			//Todo : calls a function that distinguish which of conversion we have
			if (conv_ident == 'c')
			{	
				char arg = va_arg(args, int);
				ft_putchar_fd(arg, 1);
			}
			if (conv_ident == 's')
			{
				char *arg = va_arg(args, char *);
				ft_putstr_fd(arg, 1);
			}
			if (conv_ident == '%')
			{
				ft_putchar_fd('%', 1);
			}
			if (conv_ident == 'i')
			{
				int arg = va_arg(args, int);
				ft_putnbr_fd(arg, 1);
			}
			i++;
		}
		i++;
	}

	return (0);
}

int main()
{
	ft_printf("   %c %s %% %i|%s|\n", 'a', "saad", 34567654);
	return (0);
}