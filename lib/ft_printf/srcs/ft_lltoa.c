/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:48:43 by ardurand          #+#    #+#             */
/*   Updated: 2017/11/01 15:48:45 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa(long long n)
{
	char	*str;
	size_t	len;
	int		sign;

	sign = 1;
	len = ft_nblen(n);
	str = (char *)malloc(len + 1);
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
