/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/02 08:15:41 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_and_chack_printcount(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int));
	if (c == 's')
		ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		put_number_address(va_arg(arg, void *));
	if (c == 'd')
		ft_putnbr(va_arg(arg, int));
	if (c == 'i')
		ft_putnbr(va_arg(arg, int));
	// if (c == 'u')
	// 	// .....
	if (c == 'x')
		put_number_hex_lower(va_arg(arg, int));
	if (c == 'X')
		put_number_hex_upper(va_arg(arg, int));
	if (c == '\n')
		ft_putchar('\n');
	if (c == '%')
		ft_putchar('%');
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;

	if (!str)
		return (-1);
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			get_and_chack_printcount(str[++i], arg);
		else
			ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(arg);
	return (555);
}
