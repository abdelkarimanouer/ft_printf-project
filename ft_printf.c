/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/01 18:24:49 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_char_conversions(char c)
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

static void	print_arg(va_list args, char conversions)
{
	
}

static void	get_count_conversions(const char *format, int *p_count, int *count)
{
	while (*format)
	{
		if (*format == '%' && *format + 1 == '%' && *format + 1 || *format == 10)
		{
			ft_putchar(*format);
			*p_count += 1;
			*(format)++;
		}
		else if (format[i] == '%' && format[i + 1] != '%' && format[i + 1]
			&& check_char_conversions(format[i + 1]))
		{
			*count += 1;
			i++;
		}
		else if (format[i - 1] != '%')
		{
			ft_putchar(format[i]);
			*p_count += 1;
			i++;
		}
		else
			i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		p_count;

	p_count = 0;
	count = 0;
	get_count_conversions(format, &p_count, &count, 0);
	return (p_count);
}
