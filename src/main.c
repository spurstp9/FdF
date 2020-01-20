#include "../inc/fdf.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		printf("usage: ./fdf <map>\n");
	else
		ft_fdf(argv[1]);
	return (0);
}

int	ft_fdf(char *map_path)
{
	int			fd;
	t_fdf		fdf;

	if ((fd = open((const char*)map_path, O_RDONLY)) == -1)
		return (0);
	init_fdf(&fdf, 1);
	if (check_map(fd, &fdf))
	{
		// printf("Nombre de colonnes : %d\nNombre de lignes : %d\n", fdf.map.nbcol, fdf.map.nbline);
		get_alt_max(&fdf);
		get_alt_min(&fdf);
		change_color(&fdf);
		change_fdf(&fdf, 5, 0);
		ft_display(&fdf);
	}
	free_fdf(&fdf);
	close(fd);
	return (1);
}

void	init_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 0.5;
	fdf->magn = 30;
	fdf->altitude = 3;
	fdf->x_shift = 500;
	fdf->y_shift = 200;
	fdf->x_rotation = 0.0;
	fdf->y_rotation = 0.0;
	fdf->z_rotation = 0.0;
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	fdf->mlx.img_ptr = NULL;
	fdf->nbcol = -1;
	fdf->nbline = 0;
	fdf->total = 0;
	fdf->tab = NULL;
	fdf->color_code = 1;
}

int		set_fdf_color(t_fdf *fdf)
{
	fdf->color_code %= 7;
	if (fdf->color_code == 1)
		return (BLUE);
	if (fdf->color_code == 2)
		return (GREEN);
	if (fdf->color_code == 3)
		return (ORANGE);
	if (fdf->color_code == 4)
		return (RED);
	if (fdf->color_code == 5)
		return (YELLOW);
	if (fdf->color_code == 6)
		return (WHITE);
	return (-1);
}

void	reset_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 0.5;
	fdf->altitude = 3;
	fdf->x_shift = 500;
	fdf->y_shift = 200;
	fdf->x_rotation = 0.0;
	fdf->y_rotation = 0.0;
	fdf->z_rotation = 0.0;
	change_fdf(fdf, 5, 0);
}