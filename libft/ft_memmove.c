/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:48:18 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/27 11:14:09 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ms;
	char	*md;

	if (!dst && !src)
		return (0);
	ms = (char *)src;
	md = (char *)dst;
	if (md > ms)
		while (len--)
			*(md + len) = *(ms + len);
	else
		while (len--)
			*md++ = *ms++;
	return (dst);
}
