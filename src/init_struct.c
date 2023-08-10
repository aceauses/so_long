/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:48:02 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/07 16:57:46 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*Here we initialize the structure*/
t_game	*init_struct(void)
{
	t_game	*data;

	data = malloc(sizeof(t_game));
	if (!data)
		return (free(data), NULL);
	data->map = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->players = 0;
	data->exit = 0;
	data->coins = 0;
	data->moves = 0;
	data->width = 0;
	data->height = 0;
	return (data);
}
