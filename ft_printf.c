/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:01:20 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/21 18:34:10 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sort(va_list args, char const str, int *ac)
{
	if (str == '%')
		*ac = ft_printchar('%', ac);
	if (str == 'c')
		*ac = ft_printchar(va_arg(args, int), ac);
	if (str == 's')
		*ac = ft_printstr(va_arg(args, char *), ac);
	if (str == 'd' || str == 'i')
		*ac = ft_print_di(va_arg(args, int), ac);
	if (str == 'u')
		*ac = ft_read_base(va_arg(args, unsigned int), ac, 0, 10);
	if (str == 'x')
		*ac = ft_read_base(va_arg(args, unsigned int), ac, 1, 16);
	if (str == 'X')
		*ac = ft_read_base(va_arg(args, unsigned int), ac, 2, 16);
	if (str == 'p')
		*ac = ft_memaddrs(va_arg(args, unsigned long int), ac);
	return (*ac);
}

static int	ft_checking(va_list args, char const *str, int *ac)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_sort(args, str[i + 1], ac) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (ft_printchar(str[i], ac) == -1)
				return (-1);
		}
		i++;
	}
	return (*ac);
}

int	ft_printf(char const *str, ...)
{
	int		ac;
	va_list	args;

	ac = 0;
	va_start(args, str);
	if (ft_checking(args, str, &ac) == -1)
		return (-1);
	va_end(args);
	return (ac);
}

// #include	<limits.h>

// int main(void)
// {
// 	int ret;
// 	ret = ft_printf("This is a test = %x\n", 10, "ft_printf");
// 	printf("%d\n", ret);
// 	return 0;
// }