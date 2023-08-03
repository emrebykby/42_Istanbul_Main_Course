/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:05 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/22 14:48:05 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Girdi olarak verilen char dizisinib uzunluğunu döndürür.
*/
#include "libft.h"

size_t	ft_strlen(const char *a)
{
	size_t	c;

	c = 0;
	while (a[c] != '\0')
	{
		c++;
	}
	return (c);
}
