#include "../inc/fdf.h"

int	free_check_var(char **line, char ***stock, int len, int ret)
{
	int i;

	ft_strdel(line);
	i = 0;
	while (i < len)
	{
		ft_strdel(&(*stock)[i]);
		i++;
	}
	free(*stock);
	*stock = NULL;
	if (ret == -1)
		write(1, "error\n", 6);
	return (ret);
}

int free_fdf(t_fdf *fdf, char do_exit)
{
	free(fdf->tab);
	fdf->tab = NULL;
	free(fdf->mlx.mlx_ptr);
	fdf->mlx.mlx_ptr = NULL;
	free(fdf->mlx.win_ptr);
	fdf->mlx.win_ptr = NULL;
	free(fdf->mlx.img_ptr);
	fdf->mlx.img_ptr = NULL;
	free(fdf->mlx.img_data);
	fdf->mlx.img_data = NULL;
	if (do_exit == 1)
		exit(0);
	return (1);
}