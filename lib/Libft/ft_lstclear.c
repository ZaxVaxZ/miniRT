/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:22:53 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/14 16:22:53 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*n;

	if (!lst || !(*lst) || !del)
		return ;
	p = *lst;
	n = p->next;
	while (p)
	{
		del(p->content);
		free(p);
		p = n;
		if (p)
			n = p->next;
	}
	*lst = NULL;
}
