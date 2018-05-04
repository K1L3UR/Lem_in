/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_len_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:17:40 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/30 17:17:41 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_sort_len_path(t_anthill *anthill)
{
	int		i;
	int		j;
	int		tmp;
	int		*path;

	i = 0;
	while (i < anthill->nb_path - 1)
	{
		j = i + 1;
		while (j < anthill->nb_path)
		{
			if (anthill->len_path[j] < anthill->len_path[i])
			{
				tmp = anthill->len_path[i];
				path = anthill->path[i];
				anthill->len_path[i] = anthill->len_path[j];
				anthill->path[i] = anthill->path[j];
				anthill->len_path[j] = tmp;
				anthill->path[j] = path;
			}
			j++;
		}
		i++;
	}
}

void		ft_set_len_path(t_anthill *anthill)
{
	int		i;
	int		j;

	anthill->len_path = (int*)malloc(sizeof(int) * anthill->nb_path);
	i = 0;
	while (i < anthill->nb_path)
	{
		j = 0;
		while (j < anthill->nb_room && anthill->path[i][j] != -1)
			j++;
		anthill->len_path[i] = j - 1;
		i++;
	}
	ft_sort_len_path(anthill);
}
