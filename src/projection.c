#include "../inc/fdf.h"

void	apply_proj(t_fdf *fdf, t_point *a, t_point *b)
{
	if (fdf->proj == 1)
		{
			iso(a);
			iso(b);
		}
		else
		{
			cabinet(a);
			cabinet(b);
		}
}

void	iso(t_point *p)
{
	int old_x;
	int old_y;

	old_x = p->x;
	old_y = p->y;
	(p->x) = (old_x - old_y) * cos(0.46373398);
	(p->y) = -(p->z) + (old_x + old_y) * sin(0.46373398);
}

void	cabinet(t_point *p)
{
	int old_x;
	int old_y;

	old_x = p->x;
	old_y = p->y;
	(p->x) = old_x + p->z * cos(-1) * 0.5;
	(p->y) = old_y + p->z * sin(-1) * 0.5;
}