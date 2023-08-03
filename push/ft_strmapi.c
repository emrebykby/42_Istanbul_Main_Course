/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:38:27 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/08 16:16:05 by ebuyukba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
**strmapi dizinin her karaketrine f fonkisyonunu uygular 
**ve malloc ile yeni oluşan diziyi döndürür.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	t;
	char	*buff;

	if (s == 0)
		return (NULL);
	buff = (char *)malloc(ft_strlen(s) + 1);
	if (buff == 0)
		return (NULL);
	t = 0;
	while (s[t] != '\0')
	{
		buff[t] = f(t, s[t]);
		t++;
	}
	buff[t] = '\0';
	return (buff);
}
