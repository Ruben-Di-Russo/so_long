#include "so_long.h"

void ft_printwall(t_sl sl)
{
    sl.lava = mlx_xpm_file_to_image(sl.mlx, "spritexpm/lava.xpm", &sl.img_w, &sl.img_h);
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.lava, sl.y * 64, sl.x * 64);
}

void ft_printback(t_sl sl)
{
    sl.back = mlx_xpm_file_to_image(sl.mlx, "spritexpm/background.xpm", &sl.img_w, &sl.img_h);
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.back, sl.y * 64, sl.x * 64);
}

void ft_printrogue(t_sl sl)
{
    sl.rogue = mlx_xpm_file_to_image(sl.mlx, "spritexpm/rogue.xpm", &sl.img_w, &sl.img_h);
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.rogue, sl.y * 64, sl.x * 64);
}

void ft_printexit(t_sl sl)
{
    sl.exit = mlx_xpm_file_to_image(sl.mlx, "spritexpm/exit.xpm", &sl.img_w, &sl.img_h);  
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.exit, sl.y * 64, sl.x * 64);
}

void ft_printcons(t_sl sl)
{
    sl.cons = mlx_xpm_file_to_image(sl.mlx, "spritexpm/white.xpm", &sl.img_w, &sl.img_h);
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.cons, sl.y * 64, sl.x * 64);
}

void ft_printenemy(t_sl sl)
{
    sl.enemy = mlx_xpm_file_to_image(sl.mlx, "spritexpm/enemy.xpm", &sl.img_w, &sl.img_h);
    mlx_put_image_to_window(sl.mlx, sl.mlx_win, sl.enemy, sl.y * 64, sl.x * 64);
}