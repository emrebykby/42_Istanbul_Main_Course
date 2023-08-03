/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:56:42 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/25 23:34:55 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('E', 1);
}
*/
