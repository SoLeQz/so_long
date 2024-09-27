/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:54:44 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:18 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int srcchr)
{
	int	i;

	i = ft_strlen(s);
	if (srcchr == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)srcchr)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
