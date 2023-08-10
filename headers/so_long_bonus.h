/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:14:12 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 16:23:10 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "../headers/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <math.h>
# include <fcntl.h>

# define BLK "\e[0;30m"
# define RED "\e[1;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

# define PL 32

typedef struct s_game
{
	char			**map;
	int				players;
	int				e_x;
	int				e_y;
	int				player_x;
	int				player_y;
	int				exit;
	int				moves;
	int				coins;
	int				width;
	int				height;
	mlx_image_t		*floor;
	mlx_image_t		*player;
	mlx_image_t		*p_right;
	mlx_image_t		*p_left;
	mlx_image_t		*p_up;
	mlx_image_t		*enemy;
	mlx_image_t		*moves_p;
	mlx_image_t		*coins_p;
	mlx_image_t		*exit_c;
	mlx_image_t		*exit_o;
	mlx_image_t		*coin;
	mlx_image_t		*walls;
	mlx_t			*mlx;
}	t_game;

int			main(int argc, char **argv);

/*Free And Errors*/
void		ft_free_array(char **array);
void		ft_error_free(char *s, char **map, t_game *game);
void		ft_error_free_game(char *s, t_game *game);
void		ft_error(char *s);
void		ft_error_free_map(char *s, char **map);

/*Map and validations*/
t_game		*init_struct(void);
int			get_player(char **matrix, t_game *game);
char		**copy_map(char **matrix);
void		map_validation(char *path, t_game *game);
char		**reader(char *path, t_game *game);
void		ceilings(char **matrix, t_game *game);
void		walls(char **matrix, t_game *game);
void		fill(char **matrix, int y, int x);

/*MLX*/
void		start_game(t_game *game);
void		put_images(t_game *game, char c, mlx_image_t *image);
void		key_hook(mlx_key_data_t keydata, void *param);
void		all_controls(void *param);
int			can_move_up(t_game *game);
int			can_move_down(t_game *game);
int			can_move_left(t_game *game);
int			can_move_right(t_game *game);

/*BONUS*/
void		move_vertical(t_game *game, char c);
void		move_horizontal(t_game *game, char c);
void		init_default(t_game *game);
void		init_animation(t_game *game);
int			search_for_enemy(char **map, t_game *game);
void		enemy_move(void *param);
mlx_image_t	*reload_enemy(t_game *game);
void		put_enemy(t_game *game, char c, mlx_image_t *image);
int			calculate_points(int y, int x);
void		moves_screen(t_game *game);
void		count_moves(t_game *game);
void		count_coins(t_game *game, int i);
void		lose(t_game *game);

#endif