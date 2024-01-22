/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:49 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/21 18:34:11 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	ft_printstr(char *str, int *i)
{
	int	j;

	j = 0;
	if (!str)
		str = "(null)";
	while (str[j])
	{
		if (ft_printchar(str[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
