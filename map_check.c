#include "so_long.h"

char	*get_next_line(int fd, t_sl *sl)
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
        else if (y != '0' && y != '1' && y != 'P' && y != 'E' && y != 'C' && y != 'N')
        {
            return (NULL);
        }
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

void ft_freemap(t_sl *sl)
{	
	sl->x = 0;
	while (sl->x < sl->righe)
	{
		free(sl->map[sl->x]);
		sl->x += 1;
	}
}

char	**ft_mapread(char *path, t_sl *sl)
{
	sl->x = 0;
	sl->y = 0;
    sl->righe = 0;
	sl->fd = open(path, O_RDONLY);
	sl->line = get_next_line(sl->fd, sl);
    sl->colonne = strlen(sl->line);
    sl->colonne -= 1;
    while (sl->line)
	{
		sl->righe += 1;
		sl->line = get_next_line(sl->fd, sl);
	}
    sl->fd = close(sl->fd);
    sl->fd = open(path, O_RDONLY);
    sl->line = get_next_line(sl->fd, sl);
	sl->map = malloc(sizeof(char *) * sl->righe);
	while (sl->line)
	{
		sl->map[sl->x] = strdup(sl->line);
		sl->line = get_next_line(sl->fd, sl);
		sl->x++;
	}
	return (sl->map);
}

void ft_checkcoll(t_sl *sl)
{	
    sl->map_coll = 0;
	sl->x = 0;
	while (sl->x < sl->righe)
	{
		sl->y = 0;
		while (sl->y <= sl->colonne)
		{
			if (sl->map[sl->x][sl->y] == 'C')
                sl->map_coll += 1;
			sl->y += 1;
		}
		sl->x += 1;
	}
}

// void    ft_mapcheck(t_sl *sl)
// {
//     int i;

//     sl->colonne = ft_strlen(sl->map[0]);
//     i = 0;
//     while (sl->map[i])
//         i++;
//     sl->righe = i;
// }