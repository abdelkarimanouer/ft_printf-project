/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:11 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/23 19:42:14 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ifind;

	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		ifind = 0;
		if (big[i + ifind] == little[ifind])
		{
			while ((big[i + ifind] == little[ifind])
				&& big[i + ifind] && (i + ifind) < len)
				ifind++;
			if (little[ifind] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
