/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:51:01 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/25 20:52:17 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**memchr da strchr gibi girdi karakterib
**ilk görüldüğü yerden sonrasını döndürür
**strchr dizi uzunluğunu strlen ile bilir
**ama memchr bilmediğinden girdiye ihtiayac duyar
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char) c == ((unsigned char *)s)[i])
			return ((unsigned char *) s + i);
		i++;
	}
	return (0);
}
