/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:15:43 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/03 08:39:52 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_number_hex_lower(unsigned int n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += put_number_hex_lower(n / 16);
	return (ft_putchar(hexa[n % 16]) + count);
}

static int	print_address(unsigned long n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_address(n / 16);
	return (ft_putchar(hexa[n % 16]) + count);
}

int	put_number_address(void *n)
{
	unsigned long	pn;
	int				count;

	if (!n)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	pn = (unsigned long) n;
	return (print_address(pn) + count);
}

int	put_number_hex_upper(unsigned int n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += put_number_hex_upper(n / 16);
	return (ft_putchar(hexa[n % 16]) + count);
}
