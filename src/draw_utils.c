#include "../inc/fdf.h"

void	get_point_on_the_right(t_fdf *fdf, t_map_line *line, t_point a, t_point *b)
{
	if (a.x == fdf->map.nbcol - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
	{
		b->x = a.x + 1;
		b->y = a.y;
		b->z = line->tab[a.x + 1];
	}
}

void	get_point_under(t_fdf *fdf, t_map_line *line, t_point a, t_point *b)
{
	if (a.y == fdf->map.nbline - 1)
	{
		b->x = -1;
		b->y = -1;
		b->z = -1;
	}
	else
	{
		b->x = a.x;
		b->y = a.y + 1;
		b->z = (line->next)->tab[a.x];
	}
}