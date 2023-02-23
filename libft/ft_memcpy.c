/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:36:50 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/21 00:05:04 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*md;
	char	*ms;

	if (!src && !dst)
		return (0);
	md = (char *)dst;
	ms = (char *)src;
	while (n--)
		*md++ = *ms++;
	return (dst);
}
