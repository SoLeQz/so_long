/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:31:22 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/27 13:31:06 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_floor(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.ground, x, y);
			x += data->sprites.width;
		}
		y += data->sprites.height;
	}
}

void	put_good_sprite(t_data *data, int y, int x)
{
	char	tile;

	tile = data->map.map_data[y][x];
	if (tile == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collectible, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			put_good_sprite(data, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.player,
		data->map.x_player * TILE_SIZE, data->map.y_player * TILE_SIZE);
}
