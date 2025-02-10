/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:49:13 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/09 20:10:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*aux;
	t_list	*aux_malloc;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	while (lst != NULL)
	{
		aux_malloc = f(lst->content);
		if (!aux_malloc)
			return (ft_lstclear(&new_node, del), NULL);
		aux = ft_lstnew(aux_malloc);
		if (!aux)
		{
			del(aux_malloc);
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, aux);
		lst = lst->next;
	}
	return (new_node);
}
