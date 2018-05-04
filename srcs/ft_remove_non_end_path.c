/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_non_end_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:16:54 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/30 17:16:56 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_non_end_path(t_anthill *anthill)
{
	int		i;
	int		j;
	int		sup;
	int		path_sup;

	path_sup = 0;
	i = 0;
	while (i < anthill->nb_path - path_sup)
	{
		sup = 0;
		j = 0;
		while (anthill->path[i][j] != anthill->end && anthill->path[i][j] != -1
			&& j < anthill->nb_room)
			j++;
		if (j == anthill->nb_room || anthill->path[i][j] != anthill->end)
			sup = ft_sup_path(anthill, i, path_sup++);
		if (!sup)
			i++;
	}
	anthill->nb_path -= path_sup;
}
