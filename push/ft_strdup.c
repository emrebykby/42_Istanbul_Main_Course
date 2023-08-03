/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:53:05 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 20:02:28 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**strdup gelen dizinin uzunluğu + null için 1 karakter
**ile mallocda yer açar, daha sonra bu diziye girdi diziyi kopyalar
*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	e;

	e = ft_strlen(s) + 1;
	r = malloc(e);
	if (r == 0)
		return (NULL);
	ft_memcpy(r, s, e);
	return (r);
}
