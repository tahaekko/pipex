/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:11 by msamhaou          #+#    #+#             */
/*   Updated: 2022/11/03 18:06:35 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	if (!dst && !dstsize)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	while (*dst)
		dst++;
	while (*src && dstsize-- > dlen + 1)
		*dst++ = *src++;
	*dst = '\0';
	return (slen + dlen);
}
