/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:28:39 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/27 13:46:02 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Dimensions des tuiles et de l'écran
# define TILE_SIZE 64
# define HEIGHT_MACB_SCREEN 1080
# define WIDTH_MACB_SCREEN 1920

// Structures de données

typedef struct s_map
{
	char		**map_data;
	int			width;
	int			height;
	int			x_player;
	int			y_player;
	int			p_count;
	int			e_count;
	int			c_count;
}				t_map;

typedef struct s_sprites
{
	void		*ground;
	void		*wall;
	void		*player;
	void		*player_transformed;
	void		*collectible;
	void		*exit;
	int			width;
	int			height;
}				t_sprites;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			screen_width;
	int			screen_height;
	int			move_count;
	t_map		map;
	t_sprites	sprites;
}				t_data;

// Prototypes des fonctions

// Fonctions de parsing et de validation
void			check_args(int ac, char **av);
int				check_if_ber(char *filename);
void			count_lines(t_data *data, char *filename);
void			extract_ber_data(t_data *data, char *filename);
void			check_if_valid_char(char *line);
void			check_lines_width(t_data *data);
void			check_wall(t_data *data);
void			count_objects(t_data *data);
void			check_if_finishable(t_data *data);
void			back_tracking(char **map, int y, int x);
void			check_after_back(t_data *data, char **map);
void			check_screen_size(t_data *data);

// Fonctions de chargement et de rendu de la carte
void			loading_map(t_data *data, char *filename);
void			loading_all_sprites(t_data *data);
void			loading_a_sprite(t_data *data, void **sprite, char *path);
void			render_floor(t_data *data);
void			put_good_sprite(t_data *data, int y, int x);
void			render_map(t_data *data);
void			check_tile(t_data *data, char tile, int x, int y);
void			check_vertical_walls(t_data *data);
void			check_horizontal_walls(t_data *data);

// Mouvements du joueur et gestion des événements
void			good_player_sprite(t_data *data, int new_y, int new_x);
void			moves(t_data *data, int new_y, int new_x);
int				key_pressed(int keycode, t_data *data);
void			hook_managing(t_data *data);

// Fonctions de nettoyage et de gestion des erreurs
void			cleanup(t_data *data);
int				cleanup_and_exit(t_data *data);
void			destroy_sprites(t_data *data);
void			ft_error(char *msg);
void			error_msg_free_tab(char *msg, char **tab);

// Fonctions utilitaires
char			**tab_dup(char **tab, size_t len);
void			ft_free_tab(char **tab);
int				ft_strcmp(const char *s1, const char *s2);

#endif
