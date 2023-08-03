/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:51:58 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/01 21:14:49 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girilen karakterin alfabetik veya numerik olup olmadığını kontrol eder
**ilk if içersinde alfabetik olup olmadığı else if içerisinde ise numeriklik
**kontrol edildi. Eğer sağlıyorsa 1 sağlamıyorsa 0 döndürüldü.
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
