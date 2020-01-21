#include "../inc/fdf.h"

void	apply_zoom(t_fdf *fdf, t_point *a)
{
	a->x3 = a->x * (fdf->magn * fdf->zoom);
	a->y3 = a->y * (fdf->magn * fdf->zoom);
}

// void	apply_zoom(t_fdf *fdf, t_point *a)
// {
// 	a->x2 = a->x * (30 * fdf->zoom);
// 	a->y2 = a->y * (30 * fdf->zoom);
// }

void	calculate_initial_zoom(t_fdf *fdf)
{
	if (fdf->nbline > WIN_HEIGHT / 60 || 
		fdf->nbcol > WIN_WIDTH / 60)
	{
		while (fdf->zoom >= 0.04 && fdf->nbline * fdf->zoom > WIN_HEIGHT / 60
			&& fdf->nbcol * fdf->zoom > WIN_WIDTH / 60)
			fdf->zoom -= 0.02;
	}
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
	do_calculations(fdf, 1);
}