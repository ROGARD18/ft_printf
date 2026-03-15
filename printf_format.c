/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:43:45 by anrogard          #+#    #+#             */
/*   Updated: 2025/12/09 18:55:58 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_p(unsigned long long arg)
{
	int	count;

	if (arg == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = ft_putnbr_hexa_ll_fd(arg, 1);
	if (count == -1)
		return (-1);
	return (count + 2);
}

int	print_arg_bis(char t, va_list ap)
{
	int					ag;
	unsigned long long	arg;

	ag = 0;
	if (t == 'd' || t == 'i' || t == 'u' || t == 7 || t == 'X' || t == 'x')
		ag = va_arg(ap, int);
	if (t == 'd' || t == 'i')
		return (ft_putnbr_base(ag, "0123456789", 1));
	if (t == 'u')
		return (ft_putnbr_base(ag, "0123456789", 0));
	if (t == 'x')
		return (ft_putnbr_base(ag, "0123456789abcdef", 0));
	if (t == 'X')
		return (ft_putnbr_base(ag, "0123456789ABCDEF", 0));
	if (t == '%')
		return (ft_putchar_int_fd('%', 1));
	if (t == 'p')
	{
		arg = va_arg(ap, unsigned long long);
		return (print_p(arg));
	}
	return (-2);
}

int	print_arg(char t, va_list ap)
{
	char	ag;
	char	*ag_str;

	if (t == 'c')
	{
		ag = va_arg(ap, int);
		return (ft_putchar_int_fd(ag, 1));
	}
	if (t == 's')
	{
		ag_str = va_arg(ap, char *);
		if (ag_str == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		ft_putstr_fd((char *)ag_str, 1);
		return (ft_strlen((char *)ag_str));
	}
	return (-2);
}

int	char_arg(char type, va_list ap)
{
	int	count;

	count = print_arg(type, ap);
	if (count == -2)
		count = print_arg_bis(type, ap);
	if (count == -2)
		return (-1);
	return (count);
}

int	print_format(char const *format, va_list ap)
{
	int	i;
	int	j;
	int	char_tot;
	int	count;

	i = 0;
	j = 0;
	char_tot = 0;
	while (format[i + j])
	{
		if (format[i + j] == '%')
		{
			count = char_arg(format[i + j + 1], ap);
			if (count == -1)
				return (-1);
			char_tot += count;
			i++;
		}
		else
			ft_putchar_int_fd(format[i + j], 1);
		j++;
	}
	return (char_tot + j - i);
}
