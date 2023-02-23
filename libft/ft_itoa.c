/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:51:02 by msamhaou          #+#    #+#             */
/*   Updated: 2022/10/26 16:27:23 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (len = 1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*numstr;
	int		len;
	long	n;

	n = nb;
	len = numlen(n);
	numstr = (char *)malloc((len + 1) * sizeof(char));
	if (!numstr)
		return (NULL);
	numstr[len--] = '\0';
	if (n == 0)
		numstr[0] = '0';
	if (n < 0)
	{
		numstr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		numstr[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (numstr);
}
