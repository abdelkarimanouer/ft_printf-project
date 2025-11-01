/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:40:13 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 15:37:42 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	if (!s)
		return (NULL);
	i = 0;
	ps = (unsigned char *) s;
	while (i < n)
	{
		ps[i] = c;
		i++;
	}
	return (s);
}
