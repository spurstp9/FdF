#include "../inc/fdf.h"

void	apply_shift(t_fdf *fdf, t_point *a)
{
        a->x2 += fdf->x_shift;
        a->y2 += fdf->y_shift;
}

void	apply_only_shift(t_fdf *fdf, t_point *a)
{
        a->x2 += fdf->x_incr;
        a->y2 += fdf->y_incr;
}

void	center(t_fdf *fdf)
{
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	fdf->x_incr = (WIN_WIDTH / 2) - fdf->tab[fdf->total / 2].x2;
	fdf->y_incr = (WIN_HEIGHT / 2) - fdf->tab[fdf->total / 2].y2;
	fdf->x_shift += fdf->x_incr;
	fdf->y_shift += fdf->y_incr;
	do_calculations(fdf, 2);
}

void	change_shift(t_fdf *fdf, int keycode)
{
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	if (keycode == 126)
		fdf->y_incr = 10;
	else if (keycode == 125)
		fdf->y_incr = -10;
	else if (keycode == 123)
		fdf->x_incr = 10;
	else if (keycode == 124)
		fdf->x_incr = -10;
	fdf->x_shift += fdf->x_incr;
	fdf->y_shift += fdf->y_incr;
	do_calculations(fdf, 2);
}