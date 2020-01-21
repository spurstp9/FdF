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

void    calculate_initial_shift(t_fdf *fdf)
{
    fdf->x_shift = (WIN_WIDTH - fdf->tab[fdf->total - 1].x2 - fdf->tab[0].x2) / 2;
    fdf->y_shift = (WIN_HEIGHT - fdf->tab[fdf->total - 1].y2 - fdf->tab[0].y2) / 2;
    fdf->x_incr = fdf->x_shift;
    fdf->y_incr = fdf->y_shift;
}