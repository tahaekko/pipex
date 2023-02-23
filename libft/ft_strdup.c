/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:54:26 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/29 16:47:00 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
