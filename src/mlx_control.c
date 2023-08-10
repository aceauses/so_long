/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:29:35 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/10 14:46:21 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*Key hook used for player movement and also handle the ESCAPE and close of
the game. It also prints the moves on the bash*/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		if (can_move_up(game) && ft_printf("%sMoves: %d\n", YEL, game->moves))
			game->player->instances[0].y -= PL;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		if (can_move_down(game) && ft_printf("%sMoves: %d\n", YEL, game->moves))
			game->player->instances[0].y += PL;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		if (can_move_left(game) && ft_printf("%sMoves: %d\n", YEL, game->moves))
			game->player->instances[0].x -= PL;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		if (can_move_right(game) && ft_printf("%sMoves: %d\n", YEL, game->moves))
			game->player->instances[0].x += PL;
}

/*Calculate points used calculate y and x at the power of 2
And then add them together and return the result.*/
static int	calculate_points(int y, int x)
{
	int	x_x;
	int	y_y;

	y_y = pow(y, 2);
	x_x = pow(x, 2);
	return (y_y + x_x);
}

/*Collect_coins is used to Delete images from the screen by put them
in a very random position(Not best way),
it use a proximity detection of the coins so we can know which instance
of the coin is near us and make it disapear.*/
static void	collect_coins(void *param)
{
	int		x;
	int		y;
	int		collected;
	int		i;
	t_game	*game;

	game = param;
	collected = 0;
	i = 0;
	while (i < game->coins)
	{
		x = game->player->instances[0].x - game->coin->instances[i].x;
		y = game->player->instances[0].y - game->coin->instances[i].y;
		if (calculate_points(y, x) < 32)
		{
			game->coin->instances[i].x += 9999999;
			collected++;
		}
		if (game->coins - collected < 1)
		{
			game->coins = 0;
			mlx_delete_image(game->mlx, game->coin);
		}
		i++;
	}
}

/*This function check if the all the coins have been collected and
If thats true we delete the old image of the exist and replace it
with the open one, We print that you win the game in the shell
and we close the window*/
static void	open_exit(void	*param)
{
	int		x;
	int		y;
	t_game	*game;

	game = param;
	y = game->player->instances[0].y / 32;
	x = game->player->instances[0].x / 32;
	if (game->coins == 0)
	{
		mlx_delete_image(game->mlx, game->exit_c);
		put_images(game, 'E', game->exit_o);
		if (game->map[y][x] == 'E')
		{
			ft_printf("%sYou have won!%s With %d Moves%s\n", CYN, GRN,
				game->moves, WHT);
			mlx_close_window(game->mlx);
		}
	}
}

/*Here we controll all the loop hooks*/
void	all_controls(void *param)
{
	collect_coins(param);
	open_exit(param);
}
