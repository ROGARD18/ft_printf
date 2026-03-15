/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:59:22 by anrogard          #+#    #+#             */
/*   Updated: 2025/12/06 15:40:55 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

int	ft_putchar_int_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnbr_hexa_ll_fd(unsigned long long nb, int fd)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putnbr_hexa_ll_fd(nb / 16, fd);
	count += ft_putchar_int_fd(str[nb % 16], fd);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_putnbr_base(int n, char *base, int sign)
{
	int				count;
	unsigned int	nb;
	unsigned int	len_base;

	count = 0;
	if (sign == 1 && n < 0)
	{
		count += ft_putchar_int_fd('-', 1);
		n *= -1;
	}
	nb = (unsigned int)n;
	len_base = (unsigned int)ft_strlen(base);
	if (nb >= len_base)
		count += ft_putnbr_base(nb / len_base, base, sign);
	count += ft_putchar_int_fd(base[nb % len_base], 1);
	if (count == -1)
		return (-1);
	return (count);
}
