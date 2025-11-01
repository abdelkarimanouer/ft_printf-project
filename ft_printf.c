/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/01 20:14:45 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_and_chack_printcount(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	if (c == '\n')
		ft_putchar_fd('\n', 1);
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
			ft_putchar_fd(str[i], 1);
		if (str[i])
			i++;
	}
	va_end(arg);
	return (555);
}
