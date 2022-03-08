/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:31:54 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/08 19:32:36 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	int		rd;
	char	y;
	int		i;
	char	*buffer = malloc(9999);

	i = 0;
	while ((rd = read(fd, &y, 1) > 0))
	{
		buffer[i] = y;
		i++;
		if (y == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

char	**ft_mapread(char *path, t_sl sl)
{
	char	*line;
	int		fd;

	sl.x = 0;
	sl.y = 0;
	sl.map = malloc(sizeof(char *) * 13);

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		sl.map[sl.x] = strdup(line);
		line = get_next_line(fd);
		sl.x++;
	}
	return (sl.map);
}

void	ft_printmap(t_sl sl)
{	
	sl.x = 0;
	while (sl.x < 13)
	{
		sl.y = 0;
		while (sl.y <= 25)
		{
			if (sl.map[sl.x][sl.y] == '1')
				ft_printwall(sl);
			if (sl.map[sl.x][sl.y] == '0')
				ft_printback(sl);
			if (sl.map[sl.x][sl.y] == 'P')
				ft_printrogue(sl);
			if (sl.map[sl.x][sl.y] == 'E')
				ft_printexit(sl);
			if (sl.map[sl.x][sl.y] == 'C')
				ft_printcons(sl);
			if (sl.map[sl.x][sl.y] == 'N')
				ft_printenemy(sl);
			sl.y++;
		}
		sl.x++;
	}
	
}
	
int	main(int ac, char **av)
{
	t_sl	sl;

	sl.mlx = mlx_init();
	sl.map = ft_mapread(av[1], sl);
	sl.mlx_win = mlx_new_window(sl.mlx, 25 * 64, 13 * 64, "REALM 2!!");
	ft_printmap(sl);
	mlx_loop(sl.mlx);
}
