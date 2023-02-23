/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:31:03 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/31 17:49:04 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	len = ft_strlen(s1);
	start = 0;
	end = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len-- && ft_strchr(set, s1[len]) && len >= start)
		end++;
	len = ft_strlen(s1) - start - end;
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
