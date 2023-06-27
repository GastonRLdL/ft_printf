/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:06:59 by groman-l          #+#    #+#             */
/*   Updated: 2023/05/22 19:04:10 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// Funcion que determina que imprimira
//Function that determinates what to print
static void	ft_format(char const *str, va_list arg, int *arg_len)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(arg, int), arg_len));
	if (*str == '%')
		*arg_len += write(1, "%", 1);
	if (*str == 'd' || *str == 'i')
		ft_putnum(va_arg(arg, int), arg_len);
	if (*str == 'u')
		ft_putnum_u(va_arg(arg, unsigned int), arg_len);
	if (*str == 'x' || *str == 'X')
		print_hexa(arg, arg_len, *str);
	if (*str == 'p')
		print_address_hexa(arg, arg_len);
	if (*str == 's')
		ft_putstr(va_arg(arg, char *), arg_len);
}

//Funcion principal ft_printf
//Main ft_printf function
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		arg_len;

	va_start(args, format);
	arg_len = 0;
	while (arg_len != -1 && *format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format, args, &arg_len);
		}
		else
			ft_putchar(*format, &arg_len);
		format++;
	}
	va_end(args);
	return (arg_len);
}

// #include	<limits.h>

// int main(void)
// {
//     // int ret;
//     // ret = ft_printf("This is a test = %x\n", 100, "ft_printf");
//     // printf("%x\n", 100);
// 	printf("BYTES: %d\n", ft_printf("%x\n", -1));
// 	printf("BYTES: %d\n", printf("%x\n", -1));
//     return 0;
// }