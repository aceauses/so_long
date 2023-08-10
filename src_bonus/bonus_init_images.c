/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:53:13 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 14:46:37 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

/*Here we initialize every image*/
void	init_default(t_game *game)
{
	put_images(game, '0', game->floor);
	put_images(game, '1', game->walls);
	put_images(game, 'C', game->coin);
	put_images(game, 'X', game->enemy);
	put_images(game, 'E', game->exit_c);
	put_images(game, 'P', game->player);
}

void	init_animation(t_game *game)
{
	mlx_image_to_window(game->mlx, game->p_right, game->player_x * PL,
		game->player_y * PL);
	mlx_image_to_window(game->mlx, game->p_left, game->player_x * PL,
		game->player_y * PL);
	mlx_image_to_window(game->mlx, game->p_up, game->player_x * PL,
		game->player_y * PL);
	game->p_right->instances->enabled = false;
	game->p_left->instances->enabled = false;
	game->p_up->instances->enabled = false;
}
