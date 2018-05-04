/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblpop_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:25:42 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 15:09:42 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list_dbl	*ft_lstdblpop_first(t_list_def *def)
{
	t_list_dbl	*list;

	list = def->first;
	if (def->first->next)
		def->first->next->prev = NULL;
	else
		def->last = NULL;
	def->first = def->first->next;
	list->next = NULL;
	list->prev = NULL;
	def->nb_elem--;
	return (list);
}
