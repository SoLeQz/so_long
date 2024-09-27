/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:30:56 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/27 13:31:17 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	loading_all_sprites(t_data *data)
{
	loading_a_sprite(data, &data->sprites.ground, "textures/background.xpm");
	loading_a_sprite(data, &data->sprites.wall, "textures/wall.xpm");
	loading_a_sprite(data, &data->sprites.player, "textures/player.xpm");
	loading_a_sprite(data, &data->sprites.player_transformed,
		"textures/player_win.xpm");
	loading_a_sprite(data, &data->sprites.collectible,
		"textures/collectible.xpm");
	loading_a_sprite(data, &data->sprites.exit, "textures/exit.xpm");
}

void	loading_a_sprite(t_data *data, void **sprite, char *path)
{
	*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->sprites.width,
			&data->sprites.height);
	if (!*sprite)
	{
		cleanup(data);
		ft_error("Error\nFailed to load sprites\n");
	}
}
