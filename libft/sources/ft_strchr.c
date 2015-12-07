/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:10:20 by rclanget          #+#    #+#             */
/*   Updated: 2014/11/15 10:30:16 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char	*dest;

	dest = (char *)s;
	while (*dest != c && *dest)
		dest++;
	if (*dest != c)
		return (NULL);
	return (dest);
}
