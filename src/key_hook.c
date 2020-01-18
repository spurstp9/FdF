#include "../inc/fdf.h"

void	change_altitude(t_fdf *fdf, int keycode)
{
	if (keycode == 13)
		fdf->altitude += 3;
	else if (keycode == 1)
		fdf->altitude -= 3;
}

void	change_zoom(t_fdf *fdf, int keycode)
{
	if (keycode == 24)
		fdf->zoom += 0.02;
	else if (keycode == 27)
	{
		fdf->zoom -= 0.02;
		if (fdf->zoom < 0.02)
			fdf->zoom = 0.02;
	}
}

void	change_shift(t_fdf *fdf, int keycode)
{
	if (keycode == 126)
		fdf->y_shift += 10;
	else if (keycode == 125)
		fdf->y_shift -= 10;
	else if (keycode == 123)
		fdf->x_shift += 10;
	else if (keycode == 124)
		fdf->x_shift -= 10;
}

void	change_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == 15)
		fdf->x_rotation -= 0.2;
	else if (keycode == 17)
		fdf->x_rotation += 0.2;
	else if (keycode == 3)
		fdf->y_rotation -= 0.2;
	else if (keycode == 5)
		fdf->y_rotation += 0.2;
	else if (keycode == 9)
		fdf->z_rotation -= 0.2;
	else if (keycode == 11)
		fdf->z_rotation += 0.2;
}

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
	{
		free_fdf((t_fdf*)param);
		exit(0);
	}
	else if (keycode == 13 || keycode == 1)
		change_altitude((t_fdf*)param, keycode);
	else if (keycode == 24 || keycode == 27)
		change_zoom((t_fdf*)param, keycode);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		change_shift((t_fdf*)param, keycode);
	else if (keycode == 6)
		reset_fdf((t_fdf*)param, ((t_fdf*)param)->proj);
	else if (keycode == 7)
	{
		if (((t_fdf*)param)->proj == 1)
			((t_fdf*)param)->proj = 2;
		else
			((t_fdf*)param)->proj = 1;
	}
	else if (keycode == 8 && ++(((t_fdf*)param)->color_code))
		change_color((t_fdf*)param);
	else if (keycode == 15 || keycode == 17 || keycode == 3 || keycode == 5
		|| keycode == 9 || keycode == 11)
		change_rotation((t_fdf*)param, keycode);
	ft_display((t_fdf*)param);
	return (1);
}