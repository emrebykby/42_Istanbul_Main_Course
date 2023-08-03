/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:48:09 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/05 10:08:08 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdlib.h>
#include <stdio.h>
*/
/*
**girdi olarak gelen dizinin karakter sayısını
**char c olmadan ne kadar olduğunu bulmak için ft_counta yolanır
**daha sonra bu sayı + 1 kadar mallocta yer açılır
**daha sonra bu dizi ft_split worde gönderilir.
**burada dizi cye eşit olduğu sürece ileri gidilir
**daha sonra diğer c ye gelmeden aradaki karakter sayısı alınır ve
**malloc o kadar yer açılır
**daha sonra putworde gönderilen bu dizi
**dizin ilk sırasına yazılır
**daha sonra diğer yerler için de aynı şeyler uygulanır
*/
#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (0);
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	ft_split_words(s, c, s2, num_words);
	return (s2);
}
/*
int	main(void)
{
	char *r = "www.42istanbul.com";
	char **result;
	char c;

	c = '.';
        

	result = (char **)ft_split(r, c);
	printf("Recode fonskiyon first >> %s\nSecond >> %s\nThird >> %s", 
	result[0], result[1], result[2]);
	return(0);
}
*/
