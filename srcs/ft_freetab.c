/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:15:22 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/30 17:15:23 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
		while (tab[i])
			free(tab[i++]);
	free(tab);
}
