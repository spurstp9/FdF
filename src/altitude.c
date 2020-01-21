#include "../inc/fdf.h"

void    change_altitude(t_fdf *fdf, int keycode)
{
    if (keycode == 13)
        fdf->altitude += 3;
    else if (keycode == 1)
        fdf->altitude -= 3;
    do_calculations(fdf, 1);
}

void	apply_altitude(t_fdf *fdf, t_point *a)
{
	a->z2 = a->z * (fdf->altitude * fdf->zoom);
}