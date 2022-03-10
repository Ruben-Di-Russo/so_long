/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:31:54 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:59 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_sl *sl, void *image, int x, int y)
{
	mlx_put_image_to_window(sl->mlx, sl->mlx_win, image, y * 64, x * 64);
}

void	ft_printmap(t_sl *sl)
{	
	sl->x = 0;
	while (sl->x < sl->righe)
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
}

int	lava_ani(t_sl *sl)
{
	if (sl->loop++ < 7500)
		return (0);
	sl->loop = 0;
	mlx_destroy_image(sl->mlx, sl->lava);
	if (sl->cont == 0)
	{
		sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont += 1;
	}
	else if (sl->cont == 1)
	{
		sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava2.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont = 0;
	}
	ft_printmap(sl);
	return (0);
}

int	key_hook(int keycode, t_sl *sl)
{	
	if (keycode == 53)
	{
        mlx_destroy_window(sl->mlx, sl->mlx_win);
		exit(0);
	}
	else if (keycode == 13)
	{
		move_w(sl);
		ft_printmap(sl);
	}
	else if (keycode == 1)
	{
		move_s(sl);
		ft_printmap(sl);
	}
	else if (keycode == 0)
	{
		move_a(sl);
		ft_printmap(sl);
	}
	else if (keycode == 2)
	{
		move_d(sl);
		ft_printmap(sl);
	}
	// printf("%d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_sl	sl;

	sl.mlx = mlx_init();
	sl.map = ft_mapread(av[1], &sl);
	sl.mlx_win = mlx_new_window(sl.mlx, sl.colonne * 64, sl.righe * 64, "REALM 2!!");
	if (sl.map == NULL)
	{
		mlx_destroy_window(sl.mlx, sl.mlx_win);
		exit(0);
	}
	sl.cont = 0;
	sl.loop = 0;
	sl.move = 0;
	ft_initimage(&sl);
	ft_checkcoll(&sl);
	ft_printmap(&sl);
	mlx_key_hook(sl.mlx_win, key_hook, &sl);
	mlx_loop_hook(sl.mlx, lava_ani, &sl);
	mlx_loop(sl.mlx);
}
