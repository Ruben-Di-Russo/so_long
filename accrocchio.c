/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accrocchio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:31:09 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/15 19:53:21 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_game(t_sl *sl, char **av)
{
	sl->maps_check = ft_checkmap(sl);
	sl->wall_check = ft_checkwall(sl);
	sl->arg_check = ft_argcheck(av[1]);
	if (!sl->map || !sl->maps_check || !sl->wall_check || !sl->arg_check)
	{
		printf("errore\n");
		exit(1);
		return (0);
	}
	return (1);
}

void	print_if(t_sl *sl)
{
	sl->y = 0;
	while (sl->y <= sl->colonne)
	{
		if (sl->map[sl->x][sl->y] == '1')
			ft_image(sl, sl->lava, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == '0')
			ft_image(sl, sl->back, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'P')
		{
			sl->ally_x = sl->x;
			sl->ally_y = sl->y;
			ft_image(sl, sl->rogue, sl->x, sl->y);
		}
		else if (sl->map[sl->x][sl->y] == 'E')
			ft_image(sl, sl->exit, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'C')
			ft_image(sl, sl->cons, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'N')
			ft_image(sl, sl->enemy, sl->x, sl->y);
		sl->y += 1;
	}
	sl->x += 1;
}
