#include "../incs/fdf.h"
#include <stdio.h>
#include "../../printf/includes/ft_printf.h"

//

int 		ft_putmyass(int c, t_win *win)
{
	ft_printf("c = %X\n", c);
	ft_putchar('\n');
	if (c == 0x35)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		win->mlx_ptr = NULL;
		win->win_ptr = NULL;
		ft_putstr("выходи");
		exit(0);
	}
	else
		ft_putstr("лох ");
	return (0);
}
/*
**			изометрическая проекция - меняет x и y? мб стоит назначить их double?
*/
static void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

int			main()
{
	t_win	win;
	coordinate f;
	coordinate s;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 1000, 1000, "mlx 42");
	f.x = 0;
	f.y = 0;
	s.x = 1000;
	s.y = 700;
	f.color = 0xFF00FF;
	put_line(f, s, win);
//	put_line(0, 1000, 700, 200, 0xFFFF00, win);
	mlx_key_hook(win.win_ptr, ft_putmyass, &win);
	mlx_loop(win.mlx_ptr);
}
