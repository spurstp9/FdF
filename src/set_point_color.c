#include "../inc/fdf.h"

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
		a->color = geo_mod(a->z);
}

int        geo_mod(int z)
{
    if (z <= -10)
        return (MIDNIGHT_BLUE);
    if (z < 0 && z > -10)
        return (AQUA_MARINE);
    if (z == 0)
        return (SPRING_GREEN);
    if (z > 0 && z <= 10)
        return (DARK_GREEN);
    if (z >= 10 && z < 20)
        return (SADDLEBROWN);
    if (z >= 20 && z < 30)
        return (CORAL);
    if (z >= 30)
        return (geo_mod2(z));
    return (WHITE);
}

int        geo_mod2(int z)
{
    if (z >= 30 && z < 40)
        return (GOLDEN_ROD);
    if (z >= 40 && z < 50)
        return (BEIGE);
    if (z > 50 && z < 100)
        return (WHITE_SMOKE);
    if (z > 100)
        return (WHITE);
    return (WHITE);
}