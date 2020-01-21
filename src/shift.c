#include "../inc/fdf.h"

void	adjust_3d_shift(t_fdf *fdf)
{
	t_point old;
	t_point new;

	old = fdf->tab[fdf->total / 2];
	new = old;
	apply_altitude(fdf, &new);
    apply_zoom(fdf, &new);
    apply_rotation(fdf, &new);
    fdf->x_3d_shift = (new.x3 - old.x3);
    fdf->y_3d_shift = (new.y3 - old.y3);
    fdf->z_3d_shift = (new.z3 - old.z3);
}

void	apply_3d_shift(t_fdf *fdf, t_point *a)
{
        a->x3 += fdf->x_3d_shift;
        a->y3 += fdf->y_3d_shift;
        a->z3 += fdf->z_3d_shift;
}

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

void    calculate_initial_shift(t_fdf *fdf)
{
    fdf->x_shift = (WIN_WIDTH - fdf->tab[fdf->total - 1].x2 - fdf->tab[0].x2) / 2;
    fdf->y_shift = (WIN_HEIGHT - fdf->tab[fdf->total - 1].y2 - fdf->tab[0].y2) / 2;
    fdf->x_incr = fdf->x_shift;
    fdf->y_incr = fdf->y_shift;
}

void	change_shift(t_fdf *fdf, int keycode)
{
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	if (keycode == 126)
		fdf->y_incr += 10;
	else if (keycode == 125)
		fdf->y_incr -= 10;
	else if (keycode == 123)
		fdf->x_incr += 10;
	else if (keycode == 124)
		fdf->x_incr -= 10;
	fdf->x_shift += fdf->x_incr;
	fdf->y_shift += fdf->y_incr;
	do_calculations(fdf, 2);
}