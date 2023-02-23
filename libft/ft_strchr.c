/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:10:14 by msamhaou          #+#    #+#             */
/*   Updated: 2022/11/02 16:35:15 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	slenplus;
	char	*ms;

	ms = (char *)s;
	slenplus = ft_strlen(s) + 1;
	while (slenplus--)
	{
		if (*ms == (char)c)
			return (ms);
		ms++;
	}
	return (0);
}
