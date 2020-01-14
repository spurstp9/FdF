#include "../inc/fdf.h"


// Idée : pour chaque point A =(x, y), tracer le segment [AB] et [AC] avec B = (x + 1, y), avec C = (x, y + 1)

void	draw_segment(t_fdf *fdf, t_point a, t_point b)
{
	if (b.x > -1)
	{
		// printf("Points avant la transformation : a = (%d, %d); b = (%d, %d)\n", a.x, a.y, b.x, b.y);
		apply_zoom_altitude_rotation(fdf, &a, &b);
		apply_proj(fdf, &a, &b);
		a.x += fdf->x_shift;
		b.x += fdf->x_shift;
		a.y += fdf->y_shift;
		b.y += fdf->y_shift;
		print_line_img(&(fdf->mlx), a, b);
	}
}

void	ft_display(t_fdf *fdf)
{
	if (fdf->mlx.img_ptr)
		ft_bzero(fdf->mlx.img_data, WIN_WIDTH * WIN_HEIGHT * 4);
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
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 10, 0xFDEE00,
		"----- LIST OF COMMANDS -----");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 50, 0xFDEE00,
		"Zoom out: -");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 70, 0xFDEE00,
		"Zoom in: +");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 90, 0xFDEE00,
		"Lower altitude: down arrow");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 110, 0xFDEE00,
		"Increase altitude: up arrow");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 130, 0xFDEE00,
		"Move up/down/left/right: W/S/A/D");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 150, 0xFDEE00,
		"Change projection: X");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 170, 0xFDEE00,
		"Reset projection: Z");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 190, 0xFDEE00,
		"Exit program: ESC");
}

void	draw_map(t_fdf *fdf)
{
	int i;
	int j;
	t_point a;
	t_point b;
	t_map_line *line;

	line = fdf->map.list;
	i = -1;
	while (++i < fdf->map.nbline)
	{
		a.y = i;
		j = -1;
		while (++j < fdf->map.nbcol)
		{
			a.x = j;
			a.z = line->tab[j];
			get_point_on_the_right(fdf, line, a, &b);
			draw_segment(fdf, a, b);
			get_point_under(fdf, line, a, &b);
			draw_segment(fdf, a, b);
		}
		line = line->next;
	}
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, fdf->mlx.img_ptr, 0, 0);
}