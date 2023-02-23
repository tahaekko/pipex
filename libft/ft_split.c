/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:58:56 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/29 16:38:00 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeit(char **p, size_t	index)
{
	while (index--)
		free(p[index]);
	free(p);
}

static size_t	word_count(const char	*s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static void	ft_sne(const char *s, size_t *start, size_t *end, char c)
{
	*start = *end;
	while (s[*start] == c && s[*start])
		*start += 1;
	*end = *start;
	while (s[*end] != c && s[*end])
		*end += 1;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (0);
	split = (char **)malloc((word_count(s, c) + 1) * sizeof (char *));
	if (!split)
		return (0);
	i = 0;
	end = 0;
	while (i < word_count(s, c))
	{
		ft_sne(s, &start, &end, c);
		split[i] = ft_substr(s, start, end - start);
		if (!split[i])
		{
			freeit(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
