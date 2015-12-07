/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 10:32:53 by rclanget          #+#    #+#             */
/*   Updated: 2015/02/15 19:21:01 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp_lst;
	t_list *new_lst;

	new_lst = (*f)(lst);
	tmp_lst = new_lst;
	while (lst)
	{
		lst = lst->next;
		tmp_lst->next = (*f)(lst);
		tmp_lst = tmp_lst->next;
		tmp_lst = tmp_lst->next;
	}
	return (new_lst);
}
