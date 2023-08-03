/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:20:26 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/22 15:25:17 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girdi olarak gelen diziye
**n kadar null ile yer değiştirir.
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*petty;

	petty = (unsigned char *)s;
	while (n != 0)
	{
		*petty++ = '\0';
		n--;
	}
}
