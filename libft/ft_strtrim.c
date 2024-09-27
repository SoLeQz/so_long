/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:19:01 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:18 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	int		i;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_check_set(s1[i], set))
		i++;
	size = ft_strlen(s1 + i);
	while (size != 0 && ft_check_set(s1[i + size - 1], set))
		size--;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + i, size + 1);
	return (new);
}
