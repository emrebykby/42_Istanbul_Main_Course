/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uzun bufferda çalışan.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:53:56 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/15 14:39:32 by ebuyukba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
size_t ft_strnstr(const char *big, const char *little, size_t lenght)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (little[0] == '\0')
		return (h);
	while (big[h] != '\0')
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < lenght)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return (h);
			n++;
		}
		if (little[n] == '\0')
			return (h);
		h++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char *array;
	char	*orj;
	size_t	size;
	array = (char *)malloc(42);
	orj = (char *)malloc(42);
	read(fd, array, 42);
	size = ft_strnstr(array, "\n", 42);
	ft_memcpy(orj, array, size);
	return (orj);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);

	printf(">> %s\n", get_next_line(fd));
	printf(">> %s", get_next_line(fd));
}
