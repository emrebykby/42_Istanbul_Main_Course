/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:21:50 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/25 23:32:38 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
/*
**verilen dizinin her karakterine f fonksiyonu uygulanır.
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void    a(unsigned int nbr, char *chr)
{
    *chr = 'a';
}
int main()
{
    char s[5] = "test";
    ft_striteri(s, a);
    printf("%s", s);
}
*/
