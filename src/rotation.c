#include "../inc/fdf.h"

void	apply_rotation(t_fdf *fdf, t_point *a)
{
	x_rotation(a, fdf->x_rotation);
	y_rotation(a, fdf->y_rotation);
	z_rotation(a, fdf->z_rotation);
}

void	x_rotation(t_point *a, float angle)
{
	int old_y2;
	int old_z2;

	old_y2 = a->y2;
	old_z2 = a->z2;
	a->y2 = old_y2 * cos(angle) + old_z2 * sin(angle);
	a->z2 = -old_y2 * sin(angle) + old_z2 * cos(angle);
}

void	y_rotation(t_point *a, float angle)
{
	int old_x2;
	int old_z2;

	old_x2 = a->x2;
	old_z2 = a->z2;
	a->x2 = old_x2 * cos(angle) + old_z2 * sin(angle);
	a->z2 = -old_x2 * sin(angle) + old_z2 * cos(angle);
}

void	z_rotation(t_point *a, float angle)
{
	int old_x2;
	int old_y2;

	old_x2 = a->x2;
	old_y2 = a->y2;
	a->x2 = old_x2 * cos(angle) - old_y2 * sin(angle);
	a->y2 = old_x2 * sin(angle) + old_y2 * cos(angle);
}