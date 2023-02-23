/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:39:54 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/25 19:31:54 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (0);
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(lens1 + lens2 + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, lens1);
	ft_strlcpy(str + lens1, s2, lens2 + 1);
	return (str);
}
