/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/03 09:38:46 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_and_check_printcount(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (put_number_address(va_arg(arg, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (put_number_hex_lower(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (put_number_hex_upper(va_arg(arg, unsigned int)));
	if (c == '\n')
		return (ft_putchar('\n'));
	if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		p_count;

	if (!str)
		return (-1);
	if (str[0] == '\0')
		return (0);
	i = 0;
	p_count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			p_count += get_and_check_printcount(str[++i], arg);
		else
			p_count += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(arg);
	return (p_count);
}
