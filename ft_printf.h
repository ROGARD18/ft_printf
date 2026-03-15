/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:40:32 by anrogard          #+#    #+#             */
/*   Updated: 2025/12/02 08:09:49 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_count_params(char const *format);
int	ft_putnbr_hexa_ll_fd(unsigned long long n, int fd);
int	ft_putchar_int_fd(char c, int fd);
int	ft_putnbr_base(int nb, char *base, int sign);
int	ft_putstr_fd(char *str, int fd);
int	ft_strlen(char *str);

int	print_format(char const *format, va_list ap);

#endif
