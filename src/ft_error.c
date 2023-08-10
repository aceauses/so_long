/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:45:48 by aceauses          #+#    #+#             */
/*   Updated: 2023/08/09 16:12:52 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*Free a double pointer*/
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*Exit the code and print error and free a double array*/
void	ft_error_free_map(char *s, char **map)
{
	ft_free_array(map);
	ft_putstr_fd(RED, 1);
	write(1, "Error\n", 6);
	ft_putstr_fd(YEL, 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(WHT, 1);
	exit(EXIT_FAILURE);
}

/*Just print the error and exit the code*/
void	ft_error(char *s)
{
	ft_putstr_fd(RED, 1);
	write(1, "Error\n", 6);
	ft_putstr_fd(YEL, 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(WHT, 1);
	exit(EXIT_FAILURE);
}

/*Exit the code and free map and game variable*/
void	ft_error_free(char *s, char **map, t_game *game)
{
	ft_putstr_fd(RED, 1);
	write(1, "Error\n", 6);
	ft_putstr_fd(YEL, 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(WHT, 1);
	ft_free_array(map);
	free(game);
	exit(EXIT_FAILURE);
}

/*Exit the code and free game variable*/
void	ft_error_free_game(char *s, t_game *game)
{
	ft_putstr_fd(RED, 1);
	write(1, "Error\n", 6);
	ft_putstr_fd(YEL, 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(WHT, 1);
	free(game);
	exit(EXIT_FAILURE);
}
