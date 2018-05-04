/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:17:31 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/30 17:17:32 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_sup_path(t_anthill *anthill, int num_path, int path_sup)
{
	int		i;
	int		j;
	int		**path;

	path = (int**)malloc(sizeof(int*) * (anthill->nb_path - path_sup - 1));
	i = 0;
	while (i < anthill->nb_path - path_sup - 1)
		path[i++] = (int*)malloc(sizeof(int) * (anthill->nb_room));
	i = 0;
	while (i < anthill->nb_path - path_sup)
	{
		j = 0;
		while (j < anthill->nb_room)
		{
			if (i < num_path)
				path[i][j] = anthill->path[i][j];
			else if (i > num_path)
				path[i - 1][j] = anthill->path[i][j];
			j++;
		}
		i++;
	}
	ft_freedim2((void**)anthill->path, anthill->nb_path - path_sup);
	anthill->path = path;
	return (1);
}
