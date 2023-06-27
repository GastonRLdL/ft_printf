/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:32:04 by groman-l          #+#    #+#             */
/*   Updated: 2023/05/24 15:47:42 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Imprime caracteres
//prints characters
void	ft_putchar(char c, int *arg_len)
{
	if (write(1, &c, 1) != 1)
	{
		*arg_len = -1;
		return ;
	}
	*arg_len += 1;
}

//Imprime integrales
//Prints integers

void	ft_putnum(int n, int *arg_len)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-', arg_len);
		if (*arg_len == -1)
			return ;
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnum(num / 10, arg_len);
		if (*arg_len == -1)
			return ;
		num %= 10;
		ft_putnum(num, arg_len);
		if (*arg_len == -1)
			return ;
	}
	else
		ft_putchar(num + '0', arg_len);
	if (*arg_len == -1)
		return ;
}

//Imprimme strings
//Print strings
void	ft_putstr(char *str, int *arg_len)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i], arg_len);
		if (*arg_len == -1)
			break ;
		i++;
	}
}

//Imprime integrales sin signos
//Prints unsigned integers
void	ft_putnum_u(unsigned int n, int *arg_len)
{
	if (n > 9)
	{
		ft_putnum(n / 10, arg_len);
		if (*arg_len == -1)
			return ;
		n %= 10;
	}
	ft_putchar(n + '0', arg_len);
	if (*arg_len == -1)
		return ;
}

//Imprime longs sin signos
//Prints unsigned longs
void	ft_putnum_base_ul(unsigned long n, char *base, int *len)
{
	unsigned long	arg_len;

	arg_len = 0;
	while (base[arg_len])
		arg_len++;
	if (n > arg_len -1)
	{
		ft_putnum_base_ul(n / arg_len, base, len);
		if (*len == -1)
			return ;
		n %= arg_len;
	}
	ft_putchar(base[n], len);
	if (*len == -1)
		return ;
}
