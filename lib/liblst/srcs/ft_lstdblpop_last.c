/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblpop_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:29:11 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 15:10:07 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list_dbl	*ft_lstdblpop_last(t_list_def *def)
{
	t_list_dbl	*list;

	list = def->last;
	if (def->last->prev)
		def->last->prev->next = NULL;
	else
		def->first = NULL;
	def->last = def->last->prev;
	list->next = NULL;
	list->prev = NULL;
	def->nb_elem--;
	return (list);
}
