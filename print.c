#include "so_long.h"

void ft_printwall(t_sl *sl)
{
    sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava.xpm", &sl->img_w, &sl->img_h);
}

void ft_printback(t_sl *sl)
{
    sl->back = mlx_xpm_file_to_image(sl->mlx, "spritexpm/background.xpm", &sl->img_w, &sl->img_h);
}

void ft_printrogue(t_sl *sl)
{
    sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogue.xpm", &sl->img_w, &sl->img_h);
}

void ft_printexit(t_sl *sl)
{
    sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit.xpm", &sl->img_w, &sl->img_h);  
}

void ft_printcons(t_sl *sl)
{
    sl->cons = mlx_xpm_file_to_image(sl->mlx, "spritexpm/white.xpm", &sl->img_w, &sl->img_h);
}

void ft_printenemy(t_sl *sl)
{
    sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/enemy.xpm", &sl->img_w, &sl->img_h);
}

void ft_initimage(t_sl *sl)
{
    ft_printwall(sl);
    ft_printback(sl);
    ft_printrogue(sl);
    ft_printexit(sl);
    ft_printcons(sl);
    ft_printenemy(sl);
}