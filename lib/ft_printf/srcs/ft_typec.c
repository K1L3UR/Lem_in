/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:49:58 by ardurand          #+#    #+#             */
/*   Updated: 2017/11/01 15:49:59 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_paddingchar(t_flags *flags)
{
	char	*pad;
	int		i;

	i = -1;
	pad = (char*)malloc(flags->size);
	if (flags->zero && !flags->neg)
		while (++i < flags->size - 1)
			pad[i] = '0';
	else
		while (++i < flags->size - 1)
			pad[i] = ' ';
	pad[i] = '\0';
	return (pad);
}

int		ft_padczero(t_flags *flags)
{
	char	*pad;
	int		i;

	i = -1;
	pad = (char*)malloc(flags->size - 1);
	if (flags->zero && !flags->neg)
		while (++i < flags->size - 1)
			pad[i] = '0';
	else
		while (++i < flags->size - 1)
			pad[i] = ' ';
	pad[i] = '\0';
	if (flags->neg)
	{
		write(flags->fd, "\0", 1);
		write(flags->fd, pad, ft_strlen(pad));
	}
	else
	{
		write(flags->fd, pad, ft_strlen(pad));
		write(flags->fd, "\0", 1);
	}
	free(pad);
	return (flags->size);
}

int		ft_affichec(char c, t_flags *flags)
{
	char	*pad;

	if (c == 0 && flags->size)
		return (ft_padczero(flags));
	if (flags->size > 1)
	{
		pad = ft_paddingchar(flags);
		if (!flags->neg)
			write(flags->fd, pad, ft_strlen(pad));
		write(flags->fd, &c, 1);
		if (flags->neg)
			write(flags->fd, pad, ft_strlen(pad));
		free(pad);
		return (flags->size);
	}
	write(flags->fd, &c, 1);
	return (1);
}
