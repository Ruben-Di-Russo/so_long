#include "so_long.h"

void	move_w(t_sl *sl)
{
    if (sl->map[sl->ally_x - 1][sl->ally_y] == '1')
        return ;
    else if (sl->map[sl->ally_x - 1][sl->ally_y] == 'C')
         sl->map_coll += 1;
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x - 1][sl->ally_y] = 'P';
    printf("%d\n", sl->map_coll);
}

void	move_a(t_sl *sl)
{
    if (sl->map[sl->ally_x][sl->ally_y - 1] == '1')
        return ;
    else if (sl->map[sl->ally_x][sl->ally_y - 1] == 'C')
        sl->map_coll += 1;
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x][sl->ally_y - 1] = 'P';
    printf("%d\n", sl->map_coll);
}

void	move_s(t_sl *sl)
{
    if (sl->map[sl->ally_x + 1][sl->ally_y] == '1')
        return ;
    else if (sl->map[sl->ally_x + 1][sl->ally_y] == 'C')
        sl->map_coll += 1;
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x + 1][sl->ally_y] = 'P';
    printf("%d\n", sl->map_coll);
}

void	move_d(t_sl *sl)
{
    if (sl->map[sl->ally_x][sl->ally_y + 1] == '1')
        return ;
    else if (sl->map[sl->ally_x][sl->ally_y + 1] == 'C')
        sl->map_coll += 1;
    sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x][sl->ally_y + 1] = 'P';
}