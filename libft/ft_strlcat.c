/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:22:07 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/25 23:33:57 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	originallendest;

	if (!dst && size == 0)
		return (ft_strlen(src));
	i = 0;
	lendest = ft_strlen(dst);
	originallendest = lendest;
	if (size <= lendest)
		return (size + ft_strlen(src));
	while (lendest < (size - 1) && src[i])
		dst[lendest++] = src[i++];
	dst[lendest] = '\0';
	return (originallendest + ft_strlen(src));
}
