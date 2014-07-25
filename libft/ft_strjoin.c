/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:13:36 by ycribier          #+#    #+#             */
/*   Updated: 2013/12/29 20:30:52 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	conc = (char *) malloc((len1 + len2 + 1) * sizeof(*conc));
	if (conc == NULL)
		return (NULL);
	ft_strncpy(conc, s1, len1);
	conc[len1] = '\0';
	ft_strncat(conc, s2, len2);
	return (conc);
}
