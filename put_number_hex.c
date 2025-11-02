/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:15:43 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/02 09:34:19 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_number_hex_lower(unsigned int n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	return (write(1, &hexa[n % 16], 1));
}

static int	print_address(long n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		print_address(n / 16);
	return (write(1, &hexa[n % 16], 1));
}

int	put_number_address(void *n)
{
	unsigned long	pn;
	int				count;

	count = write(1, "0x", 2);
	pn = (unsigned long) n;
	return (print_address(pn) + count);
}

int	put_number_hex_upper(unsigned int n)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	return (write(1, &hexa[n % 16], 1));
}
