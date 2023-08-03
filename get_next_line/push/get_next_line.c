/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:28:32 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/17 18:50:07 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str1)
{
	int	i;
	char	*r;

	i = 0;
	if (str1[i] == 0)
		return (NULL);
	while (str1[i] != 0 && str1[i] != '\n')
		i++;
	r = (char *)malloc((i + 2) * sizeof(char));
	if (r == 0)
		return (0);
	i = 0;
	while (str1[i] != 0 && str1[i] != '\n')
	{
		r[i] = str1[i];
		i++;
	}
	if (str1[i] == '\n')
	{
		r[i] = str1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_new_mainstr(char *mainstrsave)
{
	int	i;
	int	c;
	char	*y;

	i = 0;
	c = 0;
	while (mainstrsave[i] != '\0' && mainstrsave[i] != '\n')
		i++;
	if (mainstrsave[i] == 0)
	{
		free(mainstrsave);
		return (NULL);
	}
	y = (char *)malloc(sizeof(char) * (ft_strlen(mainstrsave) - i + 1));
	if (y == 0)
		return (NULL);
	i++;
	while (mainstrsave[i] != 0)
		y[c++] = mainstrsave[i++];
	y[c] = '\0';
	free(mainstrsave);
	return (y);
}

char	*ft_read_line(int fd, char *stread)
{
	char	*buff;
	int	rd_size;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == 0)
		return (NULL);
	rd_size = 1;
	while (ft_strchr(stread, '\n') == 0 && rd_size != 0)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (rd_size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_size] = '\0';
		stread = ft_strjoin(stread, buff);
	}
	free(buff);
	return (stread);
}

char	*get_next_line(int fd)
{
	char	*returnstr;
	static char	*mainstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	mainstr = ft_read_line(fd, mainstr);
	if (mainstr == 0)
		return (NULL);
	returnstr = ft_get_line(mainstr);
	mainstr = ft_new_mainstr(mainstr);
	return (returnstr);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	int	fd;
	char	*c;
	if (argc != 2)
	{
		printf("./a.out dosyadı.uzantı şeklinde giriş yapın");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	c = get_next_line(fd);
	while (c != NULL)
	{
		printf(">> %s", c);
		free(c);
		c = get_next_line(fd);
	}
}
*/
