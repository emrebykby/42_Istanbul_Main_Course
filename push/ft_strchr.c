/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:30:43 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 18:25:42 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**Girdi olarak verilen dizide 
**girdi olan verilen karakterin ilk görüldüğü yeri
**döndürür.
*/
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}
