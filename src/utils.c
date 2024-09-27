/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:01 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 19:27:45 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	error_msg_free_tab(char *msg, char **tab)
{
	ft_free_tab(tab);
	ft_error(msg);
}

char	**tab_dup(char **tab, size_t len)
{
	char	**new_tab;
	size_t	i;

	new_tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
		{
			ft_free_tab(new_tab);
			return (NULL);
		}
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
