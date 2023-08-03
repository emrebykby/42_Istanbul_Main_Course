/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:00:55 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/02/26 13:17:45 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**listenin sizenı döndürür.
*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	t;

	t = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		t++;
	}
	return (t);
}
