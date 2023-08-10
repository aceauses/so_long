/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:21:37 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 16:18:32 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	can_move_up(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	enemy_move(game);
	if (game->map[posy - 1][posx] == '1')
		return (0);
	if (game->map[posy - 1][posx] == 'X')
		lose(game);
	game->moves += 1;
	count_moves(game);
	if (!game->p_up->instances->enabled)
	{
		game->p_up->instances[0].x = posx * 32;
		game->p_up->instances[0].y = posy * 32;
		game->p_up->instances->enabled = true;
	}
	game->player->instances->enabled = false;
	game->p_right->instances->enabled = false;
	game->p_left->instances->enabled = false;
	return (1);
}

int	can_move_down(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	enemy_move(game);
	if (game->map[posy + 1][posx] == '1')
		return (0);
	if (game->map[posy + 1][posx] == 'X')
		lose(game);
	game->moves += 1;
	count_moves(game);
	if (!game->player->instances->enabled)
		game->player->instances->enabled = true;
	game->p_left->instances->enabled = false;
	game->p_right->instances->enabled = false;
	game->p_up->instances->enabled = false;
	return (1);
}

int	can_move_left(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	enemy_move(game);
	if (game->map[posy][posx - 1] == '1')
		return (0);
	if (game->map[posy][posx - 1] == 'X')
		lose(game);
	game->moves += 1;
	count_moves(game);
	if (!game->p_left->instances->enabled)
	{
		game->p_left->instances[0].x = posx * 32;
		game->p_left->instances[0].y = posy * 32;
		game->p_left->instances->enabled = true;
	}
	game->player->instances->enabled = false;
	game->p_right->instances->enabled = false;
	game->p_up->instances->enabled = false;
	return (1);
}

int	can_move_right(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	enemy_move(game);
	if (game->map[posy][posx + 1] == '1')
		return (0);
	if (game->map[posy][posx + 1] == 'X')
		lose(game);
	game->moves += 1;
	count_moves(game);
	if (!game->p_right->instances->enabled)
	{
		game->p_right->instances[0].x = posx * 32;
		game->p_right->instances[0].y = posy * 32;
		game->p_right->instances->enabled = true;
	}
	game->player->instances->enabled = false;
	game->p_left->instances->enabled = false;
	game->p_up->instances->enabled = false;
	return (1);
}
