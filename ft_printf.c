/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:49:09 by anrogard          #+#    #+#             */
/*   Updated: 2025/12/09 18:55:40 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		c;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	c = print_format(format, ap);
	va_end(ap);
	return (c);
}
