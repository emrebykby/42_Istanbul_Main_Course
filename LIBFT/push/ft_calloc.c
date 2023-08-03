/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:17:36 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 10:25:50 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**calloc fonskiyonu malloc ile karakter sayısı(num)
**karakterin kapladığı byte(size) 
**çarpımı kadar yer açar.
**açtığı bu yere bzero ile null ile doldurur
*/
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	void	*t;

	i = size * num;
	t = malloc(i);
	if (t == 0)
		return (t);
	ft_bzero(t, i);
	return (t);
}
