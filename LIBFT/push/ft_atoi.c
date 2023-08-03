/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:01:51 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/08 16:13:01 by ebuyukba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girilen char sayıyı integera çevirir
**isspace boşlukları ve + - atlanır.
**rakam olduğu sürece rakam rakam gidiler ve hepsi - 48
**yapılarak inte çevrilir ve o değeri neg kontrolu ile çarparak
**negatifliği sağlanır. result 10 ile çarpılarak sona bir basamak eklenir
**if ile taşma kontrol edilir.int min int max.
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') * n + (result * 10);
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		i++;
	}
	return (result);
}
