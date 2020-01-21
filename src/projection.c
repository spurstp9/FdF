#include "../inc/fdf.h"

void	change_proj(t_fdf *fdf)
{
	if (fdf->proj == 1)
		fdf->proj = 2;
	else
		fdf->proj = 1;
	reset_fdf(fdf, fdf->proj);
	do_calculations(fdf, 1);
}

void	apply_proj(t_fdf *fdf, t_point *a)
{
	if (fdf->proj == 1)
		iso(a);
	else
		cabinet(a);
}

void	iso(t_point *p)
{
	p->x2 = (p->x3 - p->y3) * cos(0.46373398);
	p->y2 = -(p->z3) + (p->x3 + p->y3) * sin(0.46373398);
}

void	cabinet(t_point *p)
{
	p->x2 = p->x3 + p->z3 * cos(-1) * 0.5;
	p->y2 = p->y3 + p->z3 * sin(-1) * 0.5;
}