/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_diupx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:40:10 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/21 18:34:12 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int n, int *i)
{
	if (n == -2147483647)
	{
		if (ft_printstr("-2147483647", i) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (ft_printchar('-', i) == -1)
				return (-1);
			n *= -1;
		}
		if (ft_read_base(n, i, 0, 10) == -1)
			return (-1);
	}
	return (*i);
}

int	ft_read_base(unsigned int n, int *i, int c, unsigned int base_n)
{
	char	*base;

	if (c == 0)
		base = "0123456789";
	if (c == 1)
		base = "0123456789abcdef";
	if (c == 2)
		base = "0123456789ABCDEF";
	if (n >= base_n)
	{
		if (ft_read_base(n / base_n, i, c, base_n) == -1)
			return (-1);
	}
	if (ft_printchar(base[n % base_n], i) == -1)
		return (-1);
	return (*i);
}

static int	ft_printptr(unsigned long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_printptr(n / 16, i) == -1)
			return (-1);
	}
	if (ft_printchar(base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	ft_memaddrs(unsigned long n, int *i)
{
	if (ft_printstr("0x", i) == -1)
		return (-1);
	if (ft_printptr(n, i) == -1)
		return (-1);
	return (*i);
}
