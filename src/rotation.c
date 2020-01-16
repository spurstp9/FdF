#include "../inc/fdf.h"

void	apply_zoom_altitude(t_fdf *fdf, t_point *a)
{
	a->x *= (30 * fdf->zoom);
	a->y *= (30 * fdf->zoom);
	a->z *= (fdf->altitude * fdf->zoom);
}

void	apply_rotation(t_fdf *fdf, t_point *a)
{
	x_rotation(a, fdf->x_rotation);
	y_rotation(a, fdf->y_rotation);
	z_rotation(a, fdf->z_rotation);
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