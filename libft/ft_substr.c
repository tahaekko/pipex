/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:02:39 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/30 14:43:11 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		str = malloc(1 * sizeof(char));
		*str = '\0';
		return (str);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
