#include "../inc/fdf.h"

void    do_calculations(t_fdf *fdf, char c)
{
    int i;
    t_point *a;

    i = 0;
    while (i < fdf->total)
    {
        a = &(fdf->tab[i]);
        if (c == 1)
        {
            apply_altitude(fdf, a);
            apply_zoom(fdf, a);
            apply_rotation(fdf, a);
            apply_proj(fdf, a);
            apply_shift(fdf, a);
        }
        else
            apply_only_shift(fdf, a);
        i++;
    }
}

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