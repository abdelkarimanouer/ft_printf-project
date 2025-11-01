/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:12:12 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/16 17:31:26 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	convert_n_str(char *str, long n, int size, char sign)
{
	if (sign == '-')
	{
		while (size > 0)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
			size--;
		}
	}
	else if (sign == '+')
	{
		while (size >= 0)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
			size--;
		}
	}
}

static char	*fill_str(char *str, int size, long ln, char sign)
{
	size += get_size(ln);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	convert_n_str(str, ln, size - 1, sign);
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	char	sign;
	long	ln;

	ln = (long)n;
	size = 0;
	sign = '+';
	if (ln < 0)
	{
		sign = '-';
		size = 1;
		ln *= -1;
	}
	str = fill_str(NULL, size, ln, sign);
	if (!str)
		return (NULL);
	if (sign == '-')
		str[0] = '-';
	return (str);
}
