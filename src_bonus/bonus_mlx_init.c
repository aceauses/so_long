/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mlx_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:35:33 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 16:04:00 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

/*Loading the PNG into texture and convert texture to images.*/
static void	init_texture(t_game *game)
{
	mlx_texture_t	*player;
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*coin;

	player = mlx_load_png("Images/player.png");
	game->player = mlx_texture_to_image(game->mlx, player);
	mlx_delete_texture(player);
	floor = mlx_load_png("Images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	walls = mlx_load_png("Images/wall.png");
	game->walls = mlx_texture_to_image(game->mlx, walls);
	mlx_delete_texture(walls);
	exit_c = mlx_load_png("Images/exit_close.png");
	game->exit_c = mlx_texture_to_image(game->mlx, exit_c);
	mlx_delete_texture(exit_c);
	coin = mlx_load_png("Images/coin.png");
	game->coin = mlx_texture_to_image(game->mlx, coin);
	mlx_delete_texture(coin);
}

/*A second function for loading images because of norm */
static void	init_texture2(t_game *game)
{
	mlx_texture_t	*exit_o;
	mlx_texture_t	*p_right;
	mlx_texture_t	*p_left;
	mlx_texture_t	*p_up;
	mlx_texture_t	*enemy;

	exit_o = mlx_load_png("Images/exit_open.png");
	game->exit_o = mlx_texture_to_image(game->mlx, exit_o);
	mlx_delete_texture(exit_o);
	p_right = mlx_load_png("Images/bonus/player_right.png");
	game->p_right = mlx_texture_to_image(game->mlx, p_right);
	mlx_delete_texture(p_right);
	p_left = mlx_load_png("Images/bonus/player_left.png");
	game->p_left = mlx_texture_to_image(game->mlx, p_left);
	mlx_delete_texture(p_left);
	p_up = mlx_load_png("Images/bonus/player_up.png");
	game->p_up = mlx_texture_to_image(game->mlx, p_up);
	mlx_delete_texture(p_up);
	enemy = mlx_load_png("Images/bonus/enemy/slime.png");
	game->enemy = mlx_texture_to_image(game->mlx, enemy);
	mlx_delete_texture(enemy);
}

/*put_images get the mlx, a character and the image and search for the character
And put the specific image in that character*/
void	put_images(t_game *game, char c, mlx_image_t *image)
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
				if (c == 'P' || c == 'C' || c == 'X')
					mlx_image_to_window(game->mlx, game->floor, x * PL, y * PL);
				mlx_image_to_window(game->mlx, image, x * PL, y * PL);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

/*Calculate points used calculate y and x at the power of 2
And then add them together and return the result.*/
int	calculate_points(int y, int x)
{
	int	x_x;
	int	y_y;

	y_y = pow(y, 2);
	x_x = pow(x, 2);
	return (y_y + x_x);
}

/*start_game is where we init the mlx and doing all the hooks and images*/
void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->width * PL, game->height * PL + 42,
			"Mystical Forest: Bonus", false);
	if (!game->mlx)
		ft_error_free("MLX Failed to initialize\n", game->map, game);
	init_texture(game);
	init_texture2(game);
	init_default(game);
	init_animation(game);
	moves_screen(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop_hook(game->mlx, &all_controls, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
