/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:38:01 by groman-l          #+#    #+#             */
/*   Updated: 2023/05/22 19:15:20 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (i);
}

void	print_hexa(va_list arg, int *arg_len, char c)
{
	unsigned int	l;

	l = va_arg(arg, unsigned int );
	if (c == 'X')
		ft_putnum_base_ul(l, "0123456789ABCDEF", arg_len);
	else
		ft_putnum_base_ul(l, "0123456789abcdef", arg_len);
}

void	print_address_hexa(va_list arg, int *arg_len)
{
	unsigned long	address;

	address = va_arg(arg, unsigned long);
	ft_putstr("0x", arg_len);
	if (*arg_len == -1)
		return ;
	ft_putnum_base_ul(address, "0123456789abcdef", arg_len);
	if (*arg_len == -1)
		return ;
}
