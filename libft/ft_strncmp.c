/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:38:42 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/27 11:15:36 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ms1;
	unsigned char	*ms2;

	ms1 = (unsigned char *)s1;
	ms2 = (unsigned char *)s2;
	while (n-- && (*ms1 || *ms2))
	{
		if (*ms1 < *ms2)
			return (-1);
		else if (*ms1 > *ms2)
			return (1);
		ms1++;
		ms2++;
	}
	return (0);
}
