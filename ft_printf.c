/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/01 17:19:26 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char_conversions(char c)
{
	char	*conversions;
	int		i;

	i = 0;
	conversions = "cspdiuxX";
	while (i < 8)
	{
		if (c == conversions[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i+ 1] == '%' && format[i + 1])
		{
			ft_putchar('%');
			i++;
		}
		else if (format[i] == 10)
		{
			ft_putchar(10);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != '%' && format[i + 1]
			&& check_char_conversions(format[i + 1]))
		{
			count++;
			i++;
		}
		else if (format[i - 1] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		else
			i++;
	}
	return (i);
}
