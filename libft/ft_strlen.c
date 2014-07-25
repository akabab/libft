/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:56:27 by ycribier          #+#    #+#             */
/*   Updated: 2013/12/29 20:28:16 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned	x;
	char		*buf;

	buf = (char *)s;
	while (1)
	{
		x = *(unsigned *)buf;
		if ((x & 0xFF) == 0)
			 return (buf - s);
		if ((x & 0xFF00) == 0)
			 return (buf - s + 1);
		if ((x & 0xFF0000) == 0)
			 return (buf - s + 2);
		if ((x & 0xFF000000) == 0)
			return (buf - s + 3);
		buf += 4;
	}
}
