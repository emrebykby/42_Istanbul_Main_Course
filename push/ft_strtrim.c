/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:27:06 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 10:06:14 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**strtrim girdi olarak gelen birinci diziden
**girdi olarak gelen ikinci diziyi
**SADECE başından ve sonundan siler ve geri kalan döner.
**static olarak kullanmamızın nedeni
**bu şekilde belirtilen fonksyonlar sadece bu dosyada kullanılabilir
**başka bir main dosyası açıp bu fonksiyonu çağırırsak
**undeclared func hatası alırız.
**bu sayede yazığımız subfuncları sadece o dosyada kullanarak 
**karışıklığı önlemiş oluruz
*/
#include "libft.h"

static int	ft_setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_setcheck(s1[start], set))
		start++;
	while (end > start && ft_setcheck(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
