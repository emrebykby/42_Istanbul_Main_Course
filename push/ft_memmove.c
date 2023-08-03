/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:11:12 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 09:11:30 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**memmove strcpy gibi bir diziyi diğer diziye kopyalar
**fakat str fonksiyonları null görünce durduğu halde
**memmove durmadan devam eder.
**overlapı önlemek için dest ile src arasındaki byte farkına bakılır
**eğer kopyalancak bytten az ise kopyalama işlemi sondan başlanır
**eğer değilse normal bir şekilde kopyalanır
**i=n - 1 mantığı diziler sıfırdan başlar.
*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
