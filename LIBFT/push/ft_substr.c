/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:20:12 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 22:34:12 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girdi olarak gelen diziden start değerinden başlayarak
**malloc ile yer açtığımız diziye strlcpy ile kopyalıyoruz.
**eğer end yani yeni dizi uzunluğu max uzunluk (len) i geçerse
**len kadar yer açarak kopyalama yapılır.
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;
	size_t	end;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	end = 0;
	if (start < s_len)
		end = s_len - start;
	if (end > len)
		end = len;
	s2 = (char *)malloc(sizeof(char) * (end + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s + start, end + 1);
	return (s2);
}
