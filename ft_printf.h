/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:09:39 by groman-l          #+#    #+#             */
/*   Updated: 2023/05/22 19:20:03 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

//Function printf

int			ft_printf(const char *format, ...);
//static void	ft_format(char const *str, va_list arg, int *arg_len);

//Functions called by ft_printf

void		ft_putchar(char c, int *base_len);
void		ft_putstr(char *s, int *base_len);
void		ft_putnum(int n, int *base_len);
void		ft_putnum_u(unsigned int n, int *base_len);
void		ft_putnum_base_ul(unsigned long n, char *base, int *len);
void		print_hexa(va_list arg, int *arg_len, char c);
void		print_address_hexa(va_list arg, int *arg_len);
#endif