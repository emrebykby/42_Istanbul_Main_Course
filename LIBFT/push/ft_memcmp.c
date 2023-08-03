/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:27:51 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/25 20:54:31 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**memcmp nullda durmaz ve devam eder yani 
**test\0\0\0 bunda ilk nullda durmaz ve kontrole devam eder.
**strncmp strcmp den farkı budur.
*/
#include "libft.h"

int	ft_memcmp(const void	*s1, const void *s2, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
