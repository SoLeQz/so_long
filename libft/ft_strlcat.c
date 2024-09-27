/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:45:19 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:24 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	lensrc;
	size_t	i;
	size_t	totallen;
	size_t	lendst;

	j = 0;
	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size > lendst)
		totallen = lendst + lensrc;
	else
		totallen = lensrc + size;
	j = lendst;
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (totallen);
}
