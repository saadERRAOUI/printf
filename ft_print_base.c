/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:41:05 by serraoui          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:54 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(unsigned long long n, const char *chars, int base, int *len)
{
	if (n >= (unsigned long long)base)
		ft_print_base(n / (unsigned long long)base, chars, base, len);
	ft_putchar(chars[n % (unsigned long long)base], len);
}
