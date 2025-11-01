/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:59:54 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/01 20:37:40 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void put_number_hex_lower(int n)
{
	char	*hexa = "0123456789abcdef";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	write(1, &hexa[n % 16], 1);
}

static void put_number_address(void * n)
{
	char			*hexa;
	unsigned long	pn;

	pn = (unsigned long) n;
	hexa = "0123456789abcdef";
	if (pn >= 16)
		put_number_hex_lower(pn / 16);
	write(1, &hexa[pn % 16], 1);
}

static void put_number_hex_upper(int n)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	write(1, &hexa[n % 16], 1);
}

static void	get_and_chack_printcount(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	if (c == 'p')
		put_number_address(va_arg(arg, void *));
	if (c == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	// if (c == 'u')
	// 	// .....
	if (c == 'x')
		put_number_hex_lower(va_arg(arg, int));
	if (c == 'X')
		put_number_hex_upper(va_arg(arg, int));
	if (c == '\n')
		ft_putchar_fd('\n', 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
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
