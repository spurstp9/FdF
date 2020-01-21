#include "../inc/fdf.h"

int main(int argc, char **argv)
{
	printf("OK");
	if (argc != 2)
		printf("usage: ./fdf <map>\n");
	else
	{
		printf("OK");
		ft_fdf(argv[1]);
	}
	return (0);
}

int	ft_fdf(char *map_path)
{
	int			fd;
	t_fdf		fdf;

	if ((fd = open((const char*)map_path, O_RDONLY)) == -1)
		return (0);
	init_fdf(&fdf, 1);
	if (check_map(fd, &fdf) > -1)
	{
		calculate_initial_zoom(&fdf);
		get_alt_max(&fdf);
		get_alt_min(&fdf);
		change_color(&fdf);
		do_calculations(&fdf, 1);
		calculate_initial_shift(&fdf);
		do_calculations(&fdf, 2);
		ft_display(&fdf);
	}
	free_fdf(&fdf);
	close(fd);
	return (1);
}

void	init_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 1;
	fdf->magn = 30;
	fdf->altitude = 0;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
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

void	reset_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 1;
	fdf->altitude = 0;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	fdf->x_rotation = 0.0;
	fdf->y_rotation = 0.0;
	fdf->z_rotation = 0.0;
	calculate_initial_zoom(fdf);
	do_calculations(fdf, 1);
	calculate_initial_shift(fdf);
	do_calculations(fdf, 2);
}

void    do_calculations(t_fdf *fdf, char c)
{
    int i;
    t_point *a;

    i = 0;
    while (i < fdf->total)
    {
        a = &(fdf->tab[i]);
        if (c == 1)
        {
            apply_altitude(fdf, a);
            apply_zoom(fdf, a);
            apply_rotation(fdf, a);
            apply_proj(fdf, a);
            apply_shift(fdf, a);
        }
        else
            apply_only_shift(fdf, a);
        i++;
    }
}