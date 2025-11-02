/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:15:43 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/02 08:32:59 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_number_hex_lower(unsigned int n)
{
	char	*hexa = "0123456789abcdef";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	return (write(1, &hexa[n % 16], 1));
}

int	put_number_address(void * n)
{
	char			*hexa;
	unsigned long	pn;

	pn = (unsigned long) n;
	hexa = "0123456789abcdef";
	if (pn >= 16)
		put_number_hex_lower(pn / 16);
	return (write(1, &hexa[pn % 16], 1));
}

int	put_number_hex_upper(unsigned int n)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
		put_number_hex_lower(n / 16);
	return (write(1, &hexa[n % 16], 1));
}