/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llbtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:48:35 by ardurand          #+#    #+#             */
/*   Updated: 2017/11/01 15:48:36 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbblen(unsigned long long n, size_t base)
{
	size_t	nb_char;

	nb_char = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		nb_char++;
		n /= base;
	}
	return (nb_char);
}

char	*ft_llbtoa(unsigned long long n, char *base)
{
	char	*str;
	size_t	len;
	size_t	len_base;

	len_base = ft_strlen(base);
	len = ft_nbblen(n, len_base);
	str = (char *)malloc(len + 1);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = base[n % len_base];
		n /= len_base;
	}
	return (str);
}
