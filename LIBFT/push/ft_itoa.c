/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:38:51 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 15:30:25 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**girdi olarak gelen int değeri chara çevirir.
**pytutorda anlatmak daha iyi
**static olarak kullanmamızın nedeni
**bu şekilde belirtilen fonksyonlar sadece bu dosyada kullanılabilir
**başka bir main dosyası açıp bu fonksiyonu çağırırsak
**undeclared func hatası alırız.
**bu sayede yazığımız subfuncları sadece o dosyada kullanarak 
**karışıklığı önlemiş oluruz
*/
#include "libft.h"

static int	new_len(int len, long nbr)
{
	if (nbr > 0)
		len = len - 1;
	return (len);
}

static char	*for_malloc(long nbr, int len)
{
	char	*tmp;

	if (nbr <= 0)
	{
		tmp = (char *)malloc(sizeof(char) * (len + 2));
		if (tmp == 0)
			return (0);
		tmp[0] = '-';
		*(tmp + len + 1) = '\0';
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp == 0)
			return (0);
		*(tmp + len) = '\0';
	}
	if (len == 0)
		tmp[0] = '0';
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

static size_t	for_len(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	long	nbr;
	size_t	len;

	nbr = n;
	len = for_len(n);
	tmp = for_malloc(nbr, len);
	len = new_len(len, nbr);
	if (tmp == 0)
		return (0);
	if (nbr == -2147483648)
	{
		nbr = ((nbr + 1) * -1) / 10;
		*(tmp + len) = '8';
		len -= 1;
	}
	else if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		*(tmp + len) = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	return (tmp);
}
