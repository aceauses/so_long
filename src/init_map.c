/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:09:26 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/07 16:52:58 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*Read map and return it in a 2D array*/
char	**reader(char *path, t_game *game)
{
	char	*array;
	char	*line;
	int		fd;
	char	**matrix;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_free_game("Invalid file\n", game);
	array = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\n')
			return (free(line), free(array), get_next_line(-1), NULL);
		array = free_join(array, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	matrix = ft_split(array, '\n');
	return (close(fd), free(array), matrix);
}

/*Get player position*/
int	get_player(char **matrix, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (matrix[y] != NULL)
	{
		while (matrix[y][x] != '\0')
		{
			if (matrix[y][x] == 'P')
			{
				game->players++;
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (game->players == 1)
		return (1);
	if (game->players > 1)
		ft_error_free_map("More than 1 Player on Map\n", matrix);
	return (0);
}

/*check bottom and top row if there are only 1*/
void	ceilings(char **matrix, t_game *game)
{
	int	x;
	int	last;

	x = 0;
	last = 0;
	while (matrix[last] != NULL)
		last++;
	while (matrix[0][x] != '\0')
		if (matrix[0][x++] != '1')
			ft_error_free("Top Row Incorrect\n", matrix, game);
	x = 0;
	while (matrix[last - 1][x] != '\0')
		if (matrix[last - 1][x++] != '1')
			ft_error_free("Bottom Row Incorrect\n", matrix, game);
}

/*Check walls and also if the map is rectangular*/
void	walls(char **matrix, t_game *game)
{
	int		y;
	size_t	x_last;

	y = 1;
	x_last = 0;
	while (matrix[0][x_last] != '\0')
			x_last++;
	while (matrix[y] != NULL)
	{
		if (ft_strlen(matrix[y]) != x_last)
			ft_error_free("Lines are not rectangular\n", matrix, game);
		if (matrix[y][0] != '1' || matrix[y][x_last - 1] != '1')
			ft_error_free("Walls Are Incorrect\n", matrix, game);
		y++;
	}
}

/*Using flood fill to find the path of the player*/
void	fill(char **matrix, int y, int x)
{
	if (matrix[y][x] == ' ' || matrix[y][x] == '1')
		return ;
	matrix[y][x] = ' ';
	fill(matrix, y, x + 1);
	fill(matrix, y, x - 1);
	fill(matrix, y + 1, x);
	fill(matrix, y - 1, x);
}
