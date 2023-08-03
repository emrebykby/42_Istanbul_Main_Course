/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:36:06 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 20:03:48 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**listenin sonuncu elamanını döndürür
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
