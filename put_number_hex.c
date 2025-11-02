/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:15:43 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/02 10:56:10 by aanouer          ###   ########.fr       */
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

static void	print_address(long n, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		*count += 1;
		print_address(n / 16, count);
	}
	write(1, &hexa[n % 16], 1);
}

int	put_number_address(void *n)
{
	unsigned long	pn;
	int				count;

	count = write(1, "0x", 2);;
	pn = (unsigned long) n;
	print_address(pn, &count);
	return (count);
}

int	put_number_hex_upper(unsigned int n)
{
	char	*hexa;
	int		count;
	
	hexa = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		put_number_hex_upper(n / 16);
	return (write(1, &hexa[n % 16], 1));
}
