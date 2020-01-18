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
	return (ret);
}

int free_fdf(t_fdf *fdf)
{
	t_map_line *line;
	t_map_line *next;

	line = fdf->map.list;
	while (line)
	{
		next = line->next;
		free(line->tab);
		free(line);
		line = next;
	}
	line = NULL;
	free(fdf->mlx.mlx_ptr);
	fdf->mlx.mlx_ptr = NULL;
	free(fdf->mlx.win_ptr);
	fdf->mlx.win_ptr = NULL;
	free(fdf->mlx.img_ptr);
	fdf->mlx.img_ptr = NULL;
	free(fdf->mlx.img_data);
	fdf->mlx.img_data = NULL;
	return (1);
}