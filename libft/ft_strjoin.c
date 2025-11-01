/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:58:44 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 15:15:15 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_str(char *fullstr, unsigned int index, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		fullstr[index++] = s[i++];
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	size_t	lens1;
	size_t	lens2;
	char	*fullstr;

	if (!s1 && !s2)
		return (NULL);
	index = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	fullstr = malloc((lens1 + lens2) + 1);
	if (fullstr == NULL)
		return (NULL);
	if (s1 != NULL)
		index = add_str(fullstr, 0, s1);
	if (s2 != NULL)
		index = add_str(fullstr, index, s2);
	fullstr[index] = '\0';
	return (fullstr);
}
