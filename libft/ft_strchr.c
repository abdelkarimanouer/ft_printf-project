/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:50 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 15:37:08 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmpc;

	if (!s)
		return (NULL);
	i = 0;
	tmpc = (char) c;
	while (s[i])
	{
		if (s[i] == tmpc)
			return ((char *) &s[i]);
		i++;
	}
	if (tmpc == s[i])
		return ((char *) &s[i]);
	return (NULL);
}
