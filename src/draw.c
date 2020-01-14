#include "../inc/fdf.h"


// Idée : pour chaque point A =(x, y), tracer le segment [AB] et [AC] avec B = (x + 1, y), avec C = (x, y + 1)

void	draw_segment(t_fdf *fdf, t_point a, t_point b)
{
	if (b.x > -1)
	{
		// printf("Points avant la transformation : a = (%d, %d); b = (%d, %d)\n", a.x, a.y, b.x, b.y);
		a.x *= (30 * fdf->zoom);
		a.y *= (30 * fdf->zoom);
		a.z *= (fdf->altitude * fdf->zoom);
		b.x *= (30 * fdf->zoom);
		b.y *= (30 * fdf->zoom);
		b.z *= (fdf->altitude * fdf->zoom);
		if (fdf->proj == 1)
		{
			iso(&a);
			iso(&b);
		}
		else
		{
			cabinet(&a);
			cabinet(&b);
		}
		a.x += fdf->x_shift;
		b.x += fdf->x_shift;
		a.y += fdf->y_shift;
		b.y += fdf->y_shift;
		print_line_img(&(fdf->mlx), a, b);
	}
}

void	iso(t_point *p)
{
	int old_x;
	int old_y;

	old_x = p->x;
	old_y = p->y;
	(p->x) = (old_x - old_y) * cos(0.46373398);
	(p->y) = -(p->z) + (old_x + old_y) * sin(0.46373398);
}

void	cabinet(t_point *p)
{
	int old_x;
	int old_y;

	old_x = p->x;
	old_y = p->y;
	(p->x) = old_x + p->z * cos(0.6) * 0.5;
	(p->y) = old_y + p->z * sin(0.6) * 0.5;
}

void	ft_display(t_fdf *fdf)
{
	int i;

	i = 0;
	// mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	if (fdf->mlx.img_ptr)
	{
		// mlx_destroy_image (fdf->mlx.mlx_ptr, fdf->mlx.img_ptr);
		ft_bzero(fdf->mlx.img_data, WIN_WIDTH * WIN_HEIGHT * 4);
	}
	if (fdf->mlx.img_ptr == NULL)
	{
		fdf->mlx.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		fdf->mlx.img_data = mlx_get_data_addr(fdf->mlx.img_ptr, &(fdf->mlx.bpp), &(fdf->mlx.size_line), &(fdf->mlx.endian));
	}
	draw_map(fdf);
	display_menu(fdf);
	mlx_hook(fdf->mlx.win_ptr, 2, 0, &key_hook, fdf);
	mlx_loop(fdf->mlx.mlx_ptr);
}

void	display_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 10, 0xFDEE00, "----- LIST OF COMMANDS -----");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 50, 0xFDEE00, "Zoom out: -");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 70, 0xFDEE00, "Zoom in: +");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 90, 0xFDEE00, "Lower altitude: down arrow");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 110, 0xFDEE00, "Increase altitude: up arrow");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 130, 0xFDEE00, "Move up/down/left/right: W/S/A/D");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 150, 0xFDEE00, "Change projection: X");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 170, 0xFDEE00, "Reset projection: Z");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 190, 0xFDEE00, "Exit program: ESC");
}

void	draw_map(t_fdf *fdf)
{
	int i;
	int j;
	t_point a;
	t_point b;
	t_map_line *line;

	line = fdf->map.list;
	i = 0;
	while (i < fdf->map.nbline)
	{
		a.y = i;
		j = 0;
		while (j < fdf->map.nbcol)
		{
			a.x = j;
			a.z = line->tab[j];
			get_point_on_the_right(fdf, line, a, &b);
			draw_segment(fdf, a, b);
			get_point_under(fdf, line, a, &b);
			draw_segment(fdf, a, b);
			j++;
		}
		i++;
		line = line->next;
	}
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, fdf->mlx.img_ptr, 0, 0);
}

void	get_point_on_the_right(t_fdf *fdf, t_map_line *line, t_point a, t_point *b)
{
	if (a.x == fdf->map.nbcol - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
	{
		b->x = a.x + 1;
		b->y = a.y;
		b->z = line->tab[a.x + 1];
	}
}

void	get_point_under(t_fdf *fdf, t_map_line *line, t_point a, t_point *b)
{
	if (a.y == fdf->map.nbline - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
	{
		b->x = a.x;
		b->y = a.y + 1;
		b->z = (line->next)->tab[a.x];
	}
}

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
	{
		free_map_lines((t_fdf*)param);
		exit(0);
	}
	if (keycode == 126)
	{
		((t_fdf*)param)->altitude += 2;
		ft_display((t_fdf*)param);
	}
	if (keycode == 125)
	{
		((t_fdf*)param)->altitude -= 2;
		ft_display((t_fdf*)param);
	}
	if (keycode == 24)
	{
		((t_fdf*)param)->zoom += 0.02;
		ft_display((t_fdf*)param);
	}
	if (keycode == 27)
	{
		((t_fdf*)param)->zoom -= 0.02;
		if (((t_fdf*)param)->zoom < 0.02)
			((t_fdf*)param)->zoom = 0.02;
		ft_display((t_fdf*)param);
	}
	if (keycode == 13)
	{
		((t_fdf*)param)->y_shift -= 5;
		ft_display((t_fdf*)param);
	}
	if (keycode == 1)
	{
		((t_fdf*)param)->y_shift += 5;
		ft_display((t_fdf*)param);
	}
	if (keycode == 0)
	{
		((t_fdf*)param)->x_shift -= 5;
		ft_display((t_fdf*)param);
	}
	if (keycode == 2)
	{
		((t_fdf*)param)->x_shift += 5;
		ft_display((t_fdf*)param);
	}
	if (keycode == 6)
	{
		((t_fdf*)param)->zoom = 0.5;
		((t_fdf*)param)->altitude = 2;
		((t_fdf*)param)->x_shift = 500;
		((t_fdf*)param)->y_shift = 200;
		ft_display((t_fdf*)param);
	}
	if (keycode == 7)
	{
		if (((t_fdf*)param)->proj == 1)
			((t_fdf*)param)->proj = 2;
		else
			((t_fdf*)param)->proj = 1;
		// init_map((t_fdf*)param, ((t_fdf*)param)->proj);
		ft_display((t_fdf*)param);
	}
	return (1);
}