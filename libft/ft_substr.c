/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:28:22 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 15:56:43 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;
	size_t	lenstr;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start >= lenstr)
		return (ft_strdup(""));
	if (len > lenstr - start)
		len = lenstr - start;
	sstr = malloc(len + 1);
	if (!sstr)
		return (NULL);
	i = 0;
	while (i < len)
		sstr[i++] = s[start++];
	sstr[i] = '\0';
	return (sstr);
}
