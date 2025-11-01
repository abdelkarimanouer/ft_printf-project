/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:32:33 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 15:56:05 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		index;
	char	tmpc;

	if (!s)
		return (NULL);
	i = 0;
	index = -1;
	tmpc = (char) c;
	while (s[i])
	{
		if (tmpc == s[i])
			index = i;
		i++;
	}
	if (tmpc == s[i])
		return ((char *) &s[i]);
	else if (index != -1)
		return ((char *) &s[index]);
	else
		return (NULL);
}
