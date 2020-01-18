#include "../inc/fdf.h"

void	apply_zoom(t_fdf *fdf, t_point *a)
{
	a->x2 = a->x * (fdf->magn * fdf->zoom);
	a->y2 = a->y * (fdf->magn * fdf->zoom);
}

// void	apply_zoom(t_fdf *fdf, t_point *a)
// {
// 	a->x2 = a->x * (30 * fdf->zoom);
// 	a->y2 = a->y * (30 * fdf->zoom);
// }