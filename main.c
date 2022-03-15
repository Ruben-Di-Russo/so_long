/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:31:54 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/15 21:12:30 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap(t_sl *sl)
{	
	char	*str;

	str = ft_itoa(sl->move);
	sl->x = 0;
	while (sl->x < sl->righe)
		print_if(sl);
	mlx_string_put(sl->mlx, sl->mlx_win, 10, 15, 0x00000000, "MOVES:");
	mlx_string_put(sl->mlx, sl->mlx_win, 80, 15, 0x00000000, str);
	free(str);
}

int	lava_ani(t_sl *sl)
{
	if (sl->loop++ < 2000)
		return (0);
	sl->loop = 0;
	if (sl->map_coll == 0)
		exit_loop(sl);
	mlx_destroy_image(sl->mlx, sl->lava);
	if (sl->cont == 0)
	{
		sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava2.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont += 1;
	}
	else if (sl->cont == 1)
	{
		sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont = 0;
	}
	ft_printmap(sl);
	return (0);
}

void	ft_image(t_sl *sl, void *image, int x, int y)
{
	mlx_put_image_to_window(sl->mlx, sl->mlx_win, image, y * 64, x * 64);
}

int	key_hook(int keycode, t_sl *sl)
{	
	if (keycode == 53)
	{
		ft_quit(sl);
	}
	else if (keycode == 13)
	{
		sl->movew = move_w(sl);
		ft_printmap(sl);
		if (sl->movew == 4)
		{
			usleep(1000000);
			exit(0);
		}
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
	return (0);
}

int	main(int ac, char **av)
{
	t_sl	sl;

	sl.bho = ac;
	sl.map = ft_mapread(av[1], &sl);
	if (sl.map)
	{
		check_game(&sl, av);
	}
	if (&check_game)
	{	
		sl.mlx = mlx_init();
		sl.mlx_win = mlx_new_window(sl.mlx, sl.colonne * 64,
				sl.righe * 64, "REALM 2!!");
		sl.cont = 0;
		sl.loop = 0;
		sl.move = 0;
		ft_initimage(&sl);
		ft_printmap(&sl);
		mlx_loop_hook(sl.mlx, lava_ani, &sl);
		mlx_key_hook(sl.mlx_win, key_hook, &sl);
		mlx_hook(sl.mlx_win, 17, 1L << 17, ft_quit, &sl);
		mlx_loop(sl.mlx);
	}	
}
