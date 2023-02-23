/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:15:58 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/19 11:23:43 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ms;

	ms = (unsigned char *)s;
	while (n--)
	{
		if (*ms == (unsigned char)c)
			return (ms);
		ms++;
	}
	return (0);
}
