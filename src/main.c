/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:27 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 19:07:32 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_error("Error\nFailed to initialize mlx\n");
	loading_map(&data, av[1]);
	hook_managing(&data);
	cleanup(&data);
	return (0);
}
