/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:52:46 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/22 15:35:39 by ebuyukba         ###   ########.tr       */
/*                               					                          */
/* ************************************************************************** */
/*
**dst sonuna src dizisini ekler. size olarak girilen değer
**null da dahil olarak copy yapılcak sizedır. 
**eğer size lendstten küçük ise
**kopyalama işlemi yapılmaz çünkü sonuna eklenemez. null için yer kalmaz.
**return değeri olarak dst yeni uzunluğu ve src nin kalan kısmınun
**uzunluğu döndülür.cpy den farkı sona ekler direkt copylemez.
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (size <= lendst)
		return (size + lensrc);
	a = 0;
	while (src[a] != '\0' && lendst + 1 < size)
	{
		dst[lendst] = src[a];
		lendst++;
		a++;
	}
	dst[lendst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[a]));
}
