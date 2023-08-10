/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:21:37 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/07 15:30:47 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	can_move_up(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	if (game->map[posy - 1][posx] == '1')
		return (0);
	game->moves += 1;
	return (1);
}

int	can_move_down(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	if (game->map[posy + 1][posx] == '1')
		return (0);
	game->moves += 1;
	return (1);
}

int	can_move_left(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	if (game->map[posy][posx - 1] == '1')
		return (0);
	game->moves += 1;
	return (1);
}

int	can_move_right(t_game *game)
{
	int		posx;
	int		posy;

	posx = game->player->instances[0].x / 32;
	posy = game->player->instances[0].y / 32;
	if (game->map[posy][posx + 1] == '1')
		return (0);
	game->moves += 1;
	return (1);
}
