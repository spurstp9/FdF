#include "../inc/fdf.h"

void	get_point_on_the_right(t_fdf *fdf, int index, t_point a, t_point *b)
{
	if (a.x == fdf->nbcol - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
		*b = (fdf->tab[index + 1]);
}

void	get_point_under(t_fdf *fdf, int index, t_point a, t_point *b)
{
	if (a.y == fdf->nbline - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
		*b = (fdf->tab[index + fdf->nbcol]);
}