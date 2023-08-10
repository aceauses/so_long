/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:21:55 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/08 13:52:39 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	move_vertical(t_game *game, char c)
{
	if (c == 'd')
	{
		game->player->instances[0].y += PL;
		game->p_up->instances[0].y += PL;
		game->p_right->instances[0].y += PL;
		game->p_left->instances[0].y += PL;
	}
	if (c == 'u')
	{
		game->player->instances[0].y -= PL;
		game->p_up->instances[0].y -= PL;
		game->p_right->instances[0].y -= PL;
		game->p_left->instances[0].y -= PL;
	}
}

void	move_horizontal(t_game *game, char c)
{
	if (c == 'r')
	{
		game->p_up->instances[0].x += PL;
		game->player->instances[0].x += PL;
		game->p_right->instances[0].x += PL;
		game->p_left->instances[0].x += PL;
	}
	if (c == 'l')
	{
		game->player->instances[0].x -= PL;
		game->p_up->instances[0].x -= PL;
		game->p_right->instances[0].x -= PL;
		game->p_left->instances[0].x -= PL;
	}
}
