/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <emrebuyukbay@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:17:16 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/03/03 22:17:31 by ebuyukba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*
**lstdelone gibi gönderilen listin sadece 1 elamanını değil 
**bütün elemanlarını temizler
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;

	if (*lst)
	{
		while (*lst)
		{
			aux_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux_lst;
		}
		*lst = 0;
	}
}
