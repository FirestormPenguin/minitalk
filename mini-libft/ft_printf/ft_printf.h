/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:25:18 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/14 16:25:20 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		len_pt(unsigned long long nb);
void	ft_put_ptr(unsigned long long nb);
int		ft_putptr(unsigned long long nb);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_conversion(va_list vl, const char format);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int nb, char *format, int base);

#endif