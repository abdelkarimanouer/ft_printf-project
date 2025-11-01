/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:11:50 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/23 13:44:35 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			totalsize;
	unsigned char	*arr;

	i = 0;
	totalsize = (count * size);
	arr = malloc(totalsize);
	if (arr == NULL)
		return (NULL);
	while (i < totalsize)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
