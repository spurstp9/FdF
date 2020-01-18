#include "../inc/fdf.h"

void	apply_shift(t_fdf *fdf, t_point *a)
{
        a->x2 += fdf->x_shift;
        a->y2 += fdf->y_shift;
}