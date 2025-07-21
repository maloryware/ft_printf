/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:00 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/05 23:40:12 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr_list;

	if (!lst || !f)
		return ;
	curr_list = lst;
	while (curr_list)
	{
		f(curr_list->content);
		curr_list = curr_list->next;
	}
}
