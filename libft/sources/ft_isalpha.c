/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:11:25 by rclanget          #+#    #+#             */
/*   Updated: 2014/11/04 18:20:25 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}
