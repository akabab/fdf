/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:23:56 by ycribier          #+#    #+#             */
/*   Updated: 2014/02/19 18:28:01 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "dlist.h"

void	dlist_push_back(t_dlist *dlist, void *value)
{
	t_dlist_node		*node;

	node = malloc(sizeof(t_dlist_node));
	if (!node)
	{
		ft_perror(NULL);
		return ;
	}
	node->value = value;
	if (dlist->last == NULL)
	{
		dlist->first = node;
		dlist->last = node;
	}
	else
	{
		dlist->last->next = node;
		node->prev = dlist->last;
		dlist->last = node;
	}
	dlist->count++;
}

void	*dlist_pop_back(t_dlist *dlist)
{
	t_dlist_node		*node;

	node = dlist->last;
	if (node)
		return (dlist_remove(dlist, node));
	return (NULL);
}

void	dlist_push_front(t_dlist *dlist, void *value)
{
	t_dlist_node		*node;

	node = malloc(sizeof(t_dlist_node));
	if (!node)
	{
		ft_perror(NULL);
		return ;
	}
	node->value = value;
	if (dlist->first == NULL)
	{
		dlist->first = node;
		dlist->last = node;
	}
	else
	{
		node->next = dlist->first;
		dlist->first->prev = node;
		dlist->first = node;
	}
	dlist->count++;
}

void	*dlist_pop_front(t_dlist *dlist)
{
	t_dlist_node		*node;

	node = dlist->first;
	if (node)
		return (dlist_remove(dlist, node));
	return (NULL);
}
