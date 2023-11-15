/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:17:04 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/15 20:59:36 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

void    ft_puthex_upper(int n, int *len);
void	ft_putchar(char c, int *len);
void    ft_putptr(unsigned long number, int *len);
void	ft_puthex(int n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_unsigned(unsigned int number, int *len);
int     ft_printf(const char *s, ...);
int     ft_putstr(char *s, int *len);

#endif
