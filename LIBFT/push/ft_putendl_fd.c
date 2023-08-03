/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:18:01 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/26 00:03:29 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int main(void)
{
        ft_putendl_fd("Emre", 1);
}
*/
