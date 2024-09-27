/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:14:32 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/27 13:29:46 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int cmp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)cmp)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)cmp)
		return ((char *)&str[i]);
	return (NULL);
}
