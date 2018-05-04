/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ant_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:17:08 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/30 17:17:09 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_ant_path(t_anthill *anthill)
{
	int		i;
	long	s;

	s = 0;
	i = 0;
	while (i < anthill->nb_path)
		s += anthill->len_path[i++];
	s += anthill->ant;
	while (s / anthill->nb_path < anthill->len_path[anthill->nb_path - 1])
	{
		s -= anthill->len_path[anthill->nb_path - 1];
		ft_sup_path(anthill, anthill->nb_path - 1, 0);
		anthill->nb_path--;
	}
	anthill->fill_ant = (int*)malloc(sizeof(int) * anthill->nb_path);
	i = -1;
	while (++i < anthill->nb_path)
		anthill->fill_ant[i] = s / anthill->nb_path - anthill->len_path[i];
	i = 0;
	while (s % anthill->nb_path)
	{
		anthill->fill_ant[i++]++;
		s--;
	}
}
