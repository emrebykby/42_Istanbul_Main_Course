/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:17 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 18:41:47 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**strnstr fonskiyonu verilen big dizisinin içinde
**little dizisini arar ve bulduğu yerden itibaren
**döndürür. eğer little boş ise direkt big döner.
**&big[h] olarak tek bir karakter döndürüryoruz.
**eğer o şekilde olmaz ise hata alırız.
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t lenght)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[h] != '\0')
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < lenght)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return ((char *)&big[h]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + h);
		h++;
	}
	return (0);
}
