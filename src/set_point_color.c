#include "../inc/fdf.h"

void    change_color(t_fdf *fdf)
{
    t_map_line *line;
    int i;
    int j;
    t_point *a;

    fdf->color = set_fdf_color(fdf);
    line = fdf->map.list;
    i = 0;
    while (i < fdf->map.nbline)
    {
        j = 0;
        while (j < fdf->map.nbcol)
        {
            a = &(line->tab[j]);
            set_point_color(fdf, a);
            j++;
        }
        i++;
        line = line->next;
    }
}

void	set_point_color(t_fdf *fdf, t_point *a)
{
	t_gradient grad;

	if (fdf->color > -1)
	{
		grad.start.z = fdf->alt_min;
		grad.start.color = fdf->color;
		grad.finish.z = fdf->alt_max;
		grad.finish.color = 0xFFFFFF;
		a->color = get_gradient(grad, *a, 3);
	}
	else
    {
        grad.start.z = geo_mode_alt(a->z, 1);
        grad.start.color = geo_mode_color(grad.start.z);
        grad.finish.z = geo_mode_alt(a->z, 2);
        grad.finish.color = geo_mode_color(grad.finish.z);
        a->color = get_gradient(grad, *a, 3);
    }
}

int        geo_mode_alt(int z, char a)
{
    if (z <= -10)
        return (-10);
    if (-10 < z && z < 0)
        return (a == 1 ? -10 : 0);
    if (z == 0)
        return (0);
    if (0 < z && z <= 10)
        return (a == 1 ? 0 : 10);
    if (10 < z && z <= 20)
        return (a == 1 ? 10 : 20);
    if (20 < z && z <= 30)
        return (a == 1 ? 20 : 30);
    if (30 < z)
        return (geo_mode_alt2(z, a));
    return (100);
}

int        geo_mode_alt2(int z, char a)
{
    if (30 < z && z <= 40)
        return (a == 1 ? 30 : 40);
    if (40 < z && z <= 50)
        return (a == 1 ? 40 : 50);
    if (50 < z && z <= 100)
        return (a == 1 ? 50 : 100);
    if (100 < z)
        return (100);
    return (100);
}

int        geo_mode_color(int z)
{
    if (z <= -10)
        return (MIDNIGHT_BLUE);
    if (-10 < z && z < 0)
        return (AQUA_MARINE);
    if (z == 0)
        return (SPRING_GREEN);
    if (0 < z && z <= 10)
        return (DARK_GREEN);
    if (10 < z && z <= 20)
        return (SADDLEBROWN);
    if (20 < z && z <= 30)
        return (CORAL);
    if (30 < z)
        return (geo_mode_color2(z));
    return (WHITE);
}

int        geo_mode_color2(int z)
{
    if (30 < z && z <= 40)
        return (GOLDEN_ROD);
    if (40 < z && z <= 50)
        return (BEIGE);
    if (50 < z && z <= 100)
        return (WHITE_SMOKE);
    if (100 < z)
        return (WHITE);
    return (WHITE);
}