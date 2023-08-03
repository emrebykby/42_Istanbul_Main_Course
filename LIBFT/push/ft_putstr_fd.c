/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:03:47 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/26 00:02:03 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int main(void)
{
	ft_putstr_fd("Emre", 1);

}
*/
