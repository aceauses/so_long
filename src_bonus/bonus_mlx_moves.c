/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mlx_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:35:55 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 14:44:00 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	moves_screen(t_game *game)
{
	char	*total_coins;

	mlx_put_string(game->mlx, "Moves:", 3, game->height * 32);
	mlx_put_string(game->mlx, "Coins:   /", 3, game->height * 32 + 20);
	total_coins = ft_itoa(game->coins);
	mlx_put_string(game->mlx, total_coins, 110, game->height * 32 + 20);
	game->moves_p = mlx_put_string(game->mlx, "0", 70, game->height * 32);
	game->coins_p = mlx_put_string(game->mlx, "0", 72, game->height * 32 + 20);
	free(total_coins);
}

void	count_moves(t_game *game)
{
	char	*total_count;

	total_count = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->moves_p);
	game->moves_p = mlx_put_string(game->mlx, total_count,
			70, game->height * 32);
	free(total_count);
}

void	count_coins(t_game *game, int i)
{
	char	*total_count;

	if (i - game->coins == 0)
		return ;
	total_count = ft_itoa(i);
	mlx_delete_image(game->mlx, game->coins_p);
	game->coins_p = mlx_put_string(game->mlx, total_count,
			70, game->height * 32 + 20);
	free(total_count);
}
