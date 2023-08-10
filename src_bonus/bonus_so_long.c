/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:32:29 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/10 14:50:01 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	get_size(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
		y++;
	game->height = y;
	game->width = ft_strlen(game->map[0]);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	game = init_struct();
	if (argc == 2)
	{
		map_validation(argv[1], game);
		get_size(game);
		start_game(game);
	}
	else
		ft_error_free_game("You have to give atleast one argument.\n", game);
	ft_free_array(game->map);
	free(game);
	return (EXIT_SUCCESS);
}
