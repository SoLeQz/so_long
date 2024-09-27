/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:32:28 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 20:07:56 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	moves(t_data *data, int y, int x)
{
	if (data->map.map_data[y][x] != '1')
	{
		data->map.y_player = y;
		data->map.x_player = x;
		if (data->map.map_data[y][x] == 'C')
		{
			data->map.map_data[y][x] = '0';
			data->map.c_count--;
		}
		if (data->map.c_count == 0)
			data->sprites.player = data->sprites.player_transformed;
		render_floor(data);
		render_map(data);
		if (data->map.c_count == 0 && data->map.map_data[y][x] == 'E')
		{
			cleanup(data);
			exit(0);
		}
	}
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 53)
		cleanup_and_exit(data);
	else if (keycode == 13)
		moves(data, data->map.y_player - 1, data->map.x_player);
	else if (keycode == 1)
		moves(data, data->map.y_player + 1, data->map.x_player);
	else if (keycode == 0)
		moves(data, data->map.y_player, data->map.x_player - 1);
	else if (keycode == 2)
		moves(data, data->map.y_player, data->map.x_player + 1);
	return (0);
}
