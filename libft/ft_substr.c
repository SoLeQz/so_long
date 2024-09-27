/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:52:22 by nicleena          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:17 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t lenght)
{
	char	*new;
	size_t	slen;
	size_t	end;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	end = 0;
	if (start > slen)
		return (ft_strdup(""));
	if (start < slen)
		end = slen - start;
	if (end > lenght)
		end = lenght;
	new = (char *)malloc(sizeof(char) * (end + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, start + s, end + 1);
	return (new);
}
