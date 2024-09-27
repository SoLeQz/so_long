/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:33:01 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 17:48:24 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hook_managing(t_data *data)
{
	data->move_count = 0;
	mlx_key_hook(data->win_ptr, key_pressed, data);
	mlx_hook(data->win_ptr, 17, 0, cleanup_and_exit, data);
	mlx_loop(data->mlx_ptr);
}

void	loading_map(t_data *data, char *filename)
{
	count_lines(data, filename);
	extract_ber_data(data, filename);
	check_lines_width(data);
	count_objects(data);
	check_wall(data);
	check_if_finishable(data);
	check_screen_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_width,
			data->screen_height, "So_long");
	if (!data->win_ptr)
		error_msg_free_tab("Error\nFailed to create window\n",
			data->map.map_data);
	loading_all_sprites(data);
	render_floor(data);
	render_map(data);
}

void	check_screen_size(t_data *data)
{
	data->screen_height = data->map.height * TILE_SIZE;
	data->screen_width = data->map.width * TILE_SIZE;
	if (data->screen_height > HEIGHT_MACB_SCREEN
		|| data->screen_width > WIDTH_MACB_SCREEN)
		error_msg_free_tab("Error\nMap size exceeds screen dimensions\n",
			data->map.map_data);
}
