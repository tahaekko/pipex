/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:22:06 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/27 11:19:12 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	while (*src && (dstsize--) - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (slen);
}
