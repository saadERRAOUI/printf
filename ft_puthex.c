/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:39:29 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/15 17:58:28 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void	ft_puthex(int n, int *len)
{
	unsigned int	number;

	number = (unsigned int)n;
	if(number < 16)
	{
		if (number < 10)
			ft_putchar(number + '0', len);   
		else
			ft_putchar(ft_tolower(number + '7'), len);
	}
	else
	{
		ft_puthex(number / 16, len);
		if ((number % 16) < 10)
			ft_putchar((number % 16) + '0', len);
		else
			ft_putchar(ft_tolower((number % 16) + '7'), len);
	}
}

void    ft_puthex_upper(int n, int *len)
{
    unsigned int number;

    number = (unsigned int)n;
    if(number < 16)
    {
        if (number < 10)
            ft_putchar(number + '0', len);   
        else
            ft_putchar(number + '7', len);
    }
    else
	{
        ft_puthex_upper(number / 16, len);
        if ((number % 16) < 10)
            ft_putchar((number % 16) + '0', len);   
        else
            ft_putchar((number % 16) + '7', len);
    }
}
