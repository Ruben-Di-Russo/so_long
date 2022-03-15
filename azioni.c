/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   azioni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:56:00 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/15 20:43:53 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_dead(t_sl *sl)
{
	mlx_destroy_image(sl->mlx, sl->rogue);
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/grave.xpm",
			&sl->img_w, &sl->img_h);
	sl->map[sl->ally_x][sl->ally_y] = 'P';
	sl->move += 1;
	return (1);
}
