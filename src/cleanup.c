/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:33:28 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 20:13:34 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	cleanup(t_data *data)
{
	destroy_sprites(data);
	ft_free_tab(data->map.map_data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
}

int	cleanup_and_exit(t_data *data)
{
	cleanup(data);
	ft_error("You quit the game. Goodbye!\n");
	exit(0);
	return (0);
}

void	destroy_sprites(t_data *data)
{
	if (data->sprites.ground)
		mlx_destroy_image(data->mlx_ptr, data->sprites.ground);
	if (data->sprites.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
	if (data->sprites.player)
		mlx_destroy_image(data->mlx_ptr, data->sprites.player);
	if (data->sprites.collectible)
		mlx_destroy_image(data->mlx_ptr, data->sprites.collectible);
	if (data->sprites.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
}
