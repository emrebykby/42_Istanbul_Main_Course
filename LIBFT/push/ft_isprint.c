/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:16:05 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/22 14:46:45 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girilen karakterin ascii tablosuna göre 
**yazdılıp yazdırılamadığını döndürür
*/
#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}
