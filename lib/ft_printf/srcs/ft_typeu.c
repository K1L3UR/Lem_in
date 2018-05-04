/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:52:21 by ardurand          #+#    #+#             */
/*   Updated: 2017/11/01 15:52:22 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_paduzero(t_flags *flags)
{
	int		i;

	i = -1;
	if (flags->neg)
	{
		write(flags->fd, "0", 1);
		if (flags->size == 0)
			return (1);
	}
	while (++i < flags->size)
		write(flags->fd, " ", 1);
	return (flags->size);
}

int		ft_afficheu(unsigned long long nb, t_flags *flags)
{
	char	*tmp;
	int		res;

	tmp = ft_llbtoa(nb, "0123456789");
	if (flags->pre > (int)ft_strlen(tmp))
		tmp = ft_prenum(tmp, flags->pre - ft_strlen(tmp));
	if (flags->pre == 0 && nb == 0)
	{
		free(tmp);
		if (flags->size > 0)
			return (ft_paduzero(flags));
		return (0);
	}
	if (flags->size > (int)ft_strlen(tmp))
	{
		flags->space = 0;
		flags->pos = 0;
		tmp = ft_paddpos(tmp, flags);
	}
	write(flags->fd, tmp, ft_strlen(tmp));
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
