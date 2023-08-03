/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:48:30 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 15:17:48 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**Girilen dizide girilen karakterin 
**son görüldüğü yerden itibaren döndürür,
**döndürme yaparken (str + i) ile götürdüğümden 
**onun int olmasını istedim. 
**strlen size_t olarak döndürüyor ve hata vermişti.
*/
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
