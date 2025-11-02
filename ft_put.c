/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:16:58 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/02 10:40:21 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		count = 1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	return (ft_putchar((n % 10) + '0') + count);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		ft_putnbr(n / 10);
	return (ft_putchar((n % 10) + '0') + count);
}
