/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:41:00 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 09:06:00 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**memcpy bizim verdiğimiz n sayısı kadar kopyalar ve 
**null'a gelip gelmediğini takmaz. Str olan fonsktonlar
**ya null ya da size olarak bakar.
*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
