/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:34:44 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/17 19:35:29 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *str, int c)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while ((char)c != str[a])
	{
		if (str[a] == '\0')
			return (0);
		a++;
	}
	return ((char *)&str[a]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s3;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s3 = (char *)malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	while (s2[j] != 0)
		s3[i++] = s2[j++];
	s3[i] = 0;
	free (s1);
	return (s3);
}
