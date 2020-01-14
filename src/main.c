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
	init_map(&fdf);
	if (check_map(fd, &fdf))
	{
		ft_display(&fdf);
	}
	free_map_lines(&fdf);
	close(fd);
	return (1);
}

void	init_map(t_fdf *fdf)
{
	fdf->proj = 1;
	fdf->zoom = 1;
	fdf->altitude = 2;
	fdf->x_shift = 500;
	fdf->y_shift = 150;
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "FdF");
	fdf->mlx.img_ptr = NULL;
	fdf->map.nbcol = -1;
	fdf->map.nbline = 0;
	fdf->map.list = NULL;
}