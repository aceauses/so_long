/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:43:24 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 16:33:04 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	search_for_enemy(char **map, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
			{
				game->e_y = y;
				game->e_x = x;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*A modified put_image just for the enemy reload on the mapp*/
void	put_enemy(t_game *game, char c, mlx_image_t *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == c)
			{
				mlx_image_to_window(game->mlx, image, x * PL, y * PL);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

/*We delete and reload back the image of the enemy in a new position*/
mlx_image_t	*reload_enemy(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	mlx_delete_image(game->mlx, game->enemy);
	texture = mlx_load_png("Images/bonus/enemy/slime.png");
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	lose(t_game *game)
{
	ft_printf("%sYou have touch a slime and lost :(%s\n", RED, WHT);
	mlx_close_window(game->mlx);
}

/*A function to randomly move the enemy on the map and reload the image*/
void	enemy_move(void *param)
{
	int		r_x;
	int		r_y;
	int		p_x;
	int		p_y;
	t_game	*game;

	game = param;
	r_x = (rand() % 3) - 1;
	r_y = (rand() % 3) - 1;
	p_x = game->player->instances[0].x / 32;
	p_y = game->player->instances[0].y / 32;
	if (!search_for_enemy(game->map, game))
		return ;
	if (game->map[game->e_y + r_y][game->e_x + r_x] != '1' &&
		game->map[game->e_y + r_y][game->e_x + r_x] != 'E' &&
		game->map[game->e_y + r_y][game->e_x + r_x] != 'X')
	{
		if (((game->e_y) - p_y) == 0 && ((game->e_x) - p_x) == 0)
			lose(game);
		game->enemy = reload_enemy(game);
		game->map[game->e_y][game->e_x] = '0';
		game->map[game->e_y + r_y][game->e_x + r_x] = 'X';
		put_enemy(game, 'X', game->enemy);
	}
}
