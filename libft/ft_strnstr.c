/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:28:46 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/31 02:11:44 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	i;
	size_t	j;

	if (!haystack && !len)
		return (0);
	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	hay = (char *)haystack;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return (hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
