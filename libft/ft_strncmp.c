/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:17:06 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:21 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	size_t	i;

	i = 0;
	if (l == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < l)
	{
		if ((s2[i] == 0 && s1[i] == 0) || i == (l - 1))
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
