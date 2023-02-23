/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:38:27 by msamhaou          #+#    #+#             */
/*   Updated: 2022/11/02 16:34:36 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slenplus;
	char	*ms;

	ms = (char *)s;
	slenplus = ft_strlen(s) + 1;
	while (slenplus--)
	{
		if (*(ms + slenplus) == (char)c)
			return (ms + slenplus);
	}
	return (0);
}
