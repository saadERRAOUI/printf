/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:52 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/12 17:25:39 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void    ft_puthex_fd(unsigned int number, int fd)
{
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

void    ft_puthex_upper_fd(unsigned int number, int fd)
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

int main() {
    ft_puthex_fd(-229743838, 1);
    printf("\n");
    ft_puthex_upper_fd(-229743838, 1);
    printf("\n%x\n", -229743838);
}