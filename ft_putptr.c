/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:43:46 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/15 23:45:20 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putptr(unsigned long number, int *len)
{
	if(number < 16)
	{
		if (number < 10)
			ft_putchar(number + '0', len);
		else
			ft_putchar(ft_tolower(number + '7'), len);
	}
	else
	{
		ft_putptr(number / 16, len);
		if ((number % 16) < 10)
			ft_putchar((number % 16) + '0', len);
		else
			ft_putchar(ft_tolower((number % 16) + '7'), len);
	}
}
