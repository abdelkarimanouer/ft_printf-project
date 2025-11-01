/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:10:27 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/23 14:30:35 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(char const *s, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (c != s[i])
		{
			size++;
			while (c != s[i] && s[i])
				i++;
		}
		else
			i++;
	}
	return (size);
}

static size_t	skip(size_t i, char c, char const *s)
{
	while (c != s[i] && s[i])
		i++;
	return (i);
}

static void	free_arr(char **arr)
{
	size_t	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		arr[index] = NULL;
		index++;
	}
	free(arr);
	arr = NULL;
}

static int	fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	int		index;
	size_t	start;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (c != s[i])
		{
			start = i;
			i = skip(i, c, s);
			arr[index] = ft_substr(s, start, i - start);
			if (!arr[index])
			{
				free_arr(arr);
				return (0);
			}
			index++;
		}
		else
			i++;
	}
	arr[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (getsize(s, c) + 1));
	if (!arr)
		return (NULL);
	if (fill_arr(arr, s, c))
		return (arr);
	else
		return (NULL);
}
