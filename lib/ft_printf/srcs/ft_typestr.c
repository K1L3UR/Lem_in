/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:52:10 by ardurand          #+#    #+#             */
/*   Updated: 2017/11/01 15:52:11 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typec(t_flags *flags, va_list *ap)
{
	wint_t	c;

	c = 0;
	if (flags->mod[0] == 'l')
	{
		c = va_arg(*ap, wint_t);
		return (ft_affichewc(c, flags));
	}
	c = (char)va_arg(*ap, int);
	return (ft_affichec(c, flags));
}

int		ft_types(t_flags *flags, va_list *ap)
{
	char	*str;
	wchar_t	*strw;

	if (!ft_strcmp(flags->mod, "l"))
	{
		strw = va_arg(*ap, wchar_t*);
		return (ft_affichews(strw, flags));
	}
	str = va_arg(*ap, char*);
	return (ft_affiches(str, flags));
}
