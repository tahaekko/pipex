/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:39:12 by msamhaou          #+#    #+#             */
/*   Updated: 2022/11/03 16:22:15 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	sc;
	char	*pm;

	sc = size * count;
	ptr = malloc((size * count) * sizeof(char));
	if (!ptr)
		return (0);
	pm = ptr;
	while (sc--)
		*pm++ = 0;
	return (ptr);
}
