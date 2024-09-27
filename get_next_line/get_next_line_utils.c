/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:45:02 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/27 13:45:13 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int srcchr)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)srcchr)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)srcchr)
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n != 0)
	{
		*c++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	verif;

	if (count != 0 && size != 0)
	{
		verif = count * size;
		if (count != verif / size)
			return (NULL);
	}
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
