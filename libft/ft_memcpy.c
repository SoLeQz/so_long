/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:30:52 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:07:14 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *) src;
	b = (char *) dst;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*b = *a;
		b++;
		a++;
	}
	return (dst);
}
