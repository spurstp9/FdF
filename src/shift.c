#include "../inc/fdf.h"

void	apply_shift(t_fdf *fdf, t_point *a)
{
        a->x2 += fdf->x_shift;
        a->y2 += fdf->y_shift;
}

void	change_shift_only(t_point *a, int keycode)
{
	if (keycode == 126)
        a->y2 += 10;
    else if (keycode == 125)
        a->y2 -= 10;
    else if (keycode == 123)
        a->x2 += 10;
    else if (keycode == 124)
        a->x2 -= 10;
}