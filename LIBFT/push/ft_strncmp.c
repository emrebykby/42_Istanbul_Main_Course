/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:36:10 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/25 20:47:16 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*bu fonksiyon girdi olarak verilen iki diziyi girdi 
**olarak verilen size kadar
**karşılaştırır eğer str1 str2 den büyük ise >0 değer 
**küçük ise <0 değer
**eşit ise =0 değer döndürür. 
**İlk while döngüsünde n kadar gezeceğimiziden nbr 
**n den az olduğu sürece döngü devam eder.
**farklı karakter görene kadar devam eder 
bu döngü return olarak aradaki farkı verir*/
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	nbr;

	nbr = 0;
	while (nbr < n && str1[nbr] != '\0')
	{
		if (str2[nbr] == '\0')
			return ((unsigned char) str1[nbr] - (unsigned char) str2[nbr]);
		else if (str1[nbr] != str2[nbr])
			return ((unsigned char) str1[nbr] - (unsigned char) str2[nbr]);
		nbr++;
	}
	if (nbr < n && str2[nbr] != '\0')
		return ((unsigned char) str1[nbr] - (unsigned char) str2[nbr]);
	return (0);
}
