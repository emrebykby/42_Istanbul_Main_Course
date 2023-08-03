/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:40:28 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 09:17:20 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*girdi olarak gelen arraya yine girdi olarak gelen
**karakteri size kadar değiştirilir yani BBBBBB olan diziyr
**int 'a' size_t 3 ile aaaBBB olarak döndürür.
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
