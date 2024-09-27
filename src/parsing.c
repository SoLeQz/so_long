/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:28:04 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 18:10:38 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int ac, char **av)
{
	if (ac != 2)
		ft_error("Error\nInvalid number of arguments\n");
	else if (!check_if_ber(av[1]))
		ft_error("Error\nMap file must have a .ber extension\n");
}

int	check_if_ber(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strcmp(&filename[len - 4], ".ber") == 0)
		return (1);
	return (0);
}

void	count_lines(t_data *data, char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFailed to open map file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.height = lines;
}

void	extract_ber_data(t_data *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	data->map.map_data = (char **)malloc(sizeof(char *) * (data->map.height
				+ 1));
	if (!data->map.map_data)
		ft_error("Error\nMemory allocation failed\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFailed to open map file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		check_if_valid_char(line);
		data->map.map_data[i] = line;
		i++;
		line = get_next_line(fd);
	}
	data->map.map_data[i] = NULL;
	close(fd);
}

void	check_if_valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			ft_error("Error\nInvalid character in map\n");
		i++;
	}
}
