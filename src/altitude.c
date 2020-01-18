#include "../inc/fdf.h"

void    change_fdf(t_fdf *fdf)
{
    t_map_line *line;
    int i;
    int j;
    t_point *a;

    line = fdf->map.list;
    i = 0;
    while (i < fdf->map.nbline)
    {
        j = 0;
        while (j < fdf->map.nbcol)
        {
            a = &(line->tab[j]);
            apply_altitude(fdf, a);
            apply_zoom(fdf, a);
            apply_rotation(fdf, a);
            apply_proj(fdf, a);
            apply_shift(fdf, a);
            j++;
        }
        i++;
        line = line->next;
    }
}

void	apply_altitude(t_fdf *fdf, t_point *a)
{
	a->z2 = a->z * (fdf->altitude * fdf->zoom);
}