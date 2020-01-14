#include "../inc/fdf.h"

void	apply_zoom_altitude_rotation(t_fdf *fdf, t_point *a, t_point *b)
{
	a->x *= (30 * fdf->zoom);
	a->y *= (30 * fdf->zoom);
	a->z *= (fdf->altitude * fdf->zoom);
	b->x *= (30 * fdf->zoom);
	b->y *= (30 * fdf->zoom);
	b->z *= (fdf->altitude * fdf->zoom);
	x_rotation(a, fdf->x_rotation);
	x_rotation(b, fdf->x_rotation);
	y_rotation(a, fdf->y_rotation);
	y_rotation(b, fdf->y_rotation);
	z_rotation(a, fdf->z_rotation);
	z_rotation(b, fdf->z_rotation);
}

void	x_rotation(t_point *a, float angle)
{
	int old_x;
	int old_y;
	int old_z;

	old_x = a->x;
	old_y = a->y;
	old_z = a->z;
	a->y = old_y * cos(angle) + old_z * sin(angle);
	a->z = -old_y * sin(angle) + old_z * cos(angle);
}

void	y_rotation(t_point *a, float angle)
{
	int old_x;
	int old_y;
	int old_z;

	old_x = a->x;
	old_y = a->y;
	old_z = a->z;
	a->x = old_x * cos(angle) + old_z * sin(angle);
	a->z = -old_x * sin(angle) + old_z * cos(angle);
}

void	z_rotation(t_point *a, float angle)
{
	int old_x;
	int old_y;
	int old_z;

	old_x = a->x;
	old_y = a->y;
	old_z = a->z;
	a->x = old_x * cos(angle) - old_y * sin(angle);
	a->y = old_x * sin(angle) + old_y * cos(angle);
}