/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:39:56 by aannunzi          #+#    #+#             */
/*   Updated: 2022/03/10 19:46:30 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct sl
{
	char	**map;
	char	**maptemp;
	char 	*line;
	void	*mlx;
	void	*mlx_win;
    void	*lava;
	void	*back;
	void	*rogue;
	void	*exit;
	void	*cons;
	void	*enemy;
	int		img_w;
	int		img_h;
	int		ally_x;
	int		ally_y;
	int		map_wall;
	int		map_exit;
	int		map_coll;
	int		map_ally;
	int		x;
	int		y;
	int		cont;
	int		loop;
	int		move;
	int		colonne;
	int		righe;
	int 	fd;
}				t_sl;

void	ft_printwall(t_sl *sl);
void	ft_printback(t_sl *sl);
void	ft_printrogue(t_sl *sl);
void	ft_printexit(t_sl *sl);
void	ft_printcons(t_sl *sl);
void	ft_printenemy(t_sl *sl);
void	move_w(t_sl *sl);
void	move_a(t_sl *sl);
void	move_s(t_sl *sl);
void	move_d(t_sl *sl);
void 	ft_initimage(t_sl *sl);
int		lava_ani(t_sl *sl);
char	**ft_mapread(char *path, t_sl *sl);
char	*get_next_line(int fd, t_sl *sl);
void	ft_checkcoll(t_sl *sl);
void ft_freemap(t_sl *sl);

#endif