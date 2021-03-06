/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:31:07 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 23:26:11 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*istr;
	long int		i;
	unsigned int	len;
	unsigned int	flag;

	flag = (n < 0) ? 1 : 0;
	i = (flag) ? (long int)n * -1 : n;
	len = 0;
	while (n && ++len)
		n /= 10;
	len += (!len) ? 1 : 0;
	if (!(istr = (char*)malloc(sizeof(*istr) * (len + flag + 1))))
		return (NULL);
	*istr = '-';
	istr += flag;
	istr[len--] = '\0';
	istr += len;
	while (len)
	{
		*istr-- = ((i % 10) + '0');
		i /= 10;
		len--;
	}
	*istr = ((i % 10) + '0');
	return (istr - flag);
}
