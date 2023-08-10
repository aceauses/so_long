/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:02:46 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/08 15:14:35 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

/*A function to recheck the result of flood fill
If the function found C or E its mean that flood fill could fill it ==
 Invalid path*/
static int	recheck(char **matrix)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (matrix[y] != NULL)
	{
		while (matrix[y][x] != '\0')
		{
			if (matrix[y][x] == 'C' || matrix[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

/*Function to copy a double pointer and return a new double pointer*/
char	**copy_map(char **matrix)
{
	char	**copied;
	int		y;

	y = 0;
	while (matrix[y] != NULL)
		y++;
	copied = malloc(sizeof(char *) * (y + 1));
	y = 0;
	while (matrix[y] != NULL)
	{
		copied[y] = ft_strdup(matrix[y]);
		y++;
	}
	copied[y] = NULL;
	return (copied);
}

/*check the extension to be .ber*/
static void	map_extension(char *path, char **map, t_game *game)
{
	char	*ext;

	ext = ft_strchr(path, '.');
	if (!ext)
		ft_error_free("File must contain a .ber extension\n", map, game);
	if (ft_strncmp(ext, ".ber", 4) == 0 && ft_strlen(ext) == 4)
		return ;
	else
		ft_error_free("Wrong file extension\n", map, game);
}

/*Check for Coins to be atleast 1 and for exit to be only 1
Also check for invalid character and helps for the map validations*/
static void	get_objects(char **map, t_game *game)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				game->coins++;
			if (map[y][x] == 'E')
				game->exit++;
			if (map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '0'
			&& map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'X')
				ft_error_free("Found wrong Character in the Map\n", map, game);
			x++;
		}
		y++;
		x = 0;
	}
	if (game->exit != 1)
		ft_error_free("More or Less than one Exit\n", map, game);
	if (game->coins < 1)
		ft_error_free("Less than 1 Coin on the map\n", map, game);
}

void	map_validation(char *path, t_game *game)
{
	char	**matrix;
	char	**c_matrix;

	matrix = reader(path, game);
	if (!matrix)
		ft_error_free_game("Newlines inside the map\n", game);
	map_extension(path, matrix, game);
	if (!get_player(matrix, game))
		ft_error_free("Player not found\n", matrix, game);
	ceilings(matrix, game);
	walls(matrix, game);
	get_objects(matrix, game);
	c_matrix = copy_map(matrix);
	fill(c_matrix, game->player_y, game->player_x);
	if (!(recheck(c_matrix)))
	{
		ft_free_array(matrix);
		ft_error_free("Invalid Path\n", c_matrix, game);
	}
	game->map = copy_map(matrix);
	ft_free_array(matrix);
	ft_free_array(c_matrix);
}
