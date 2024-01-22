/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:25 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/21 18:34:11 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_printchar(char c, int *i);
int	ft_printstr(char *str, int *i);

int	ft_print_di(int n, int *i);
int	ft_read_base(unsigned int n, int *i, int c, unsigned int base_n);
int	ft_memaddrs(unsigned long n, int *i);

#endif