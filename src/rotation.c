#include "../inc/fdf.h"

void	change_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == 15)
		fdf->x_rotation -= 0.2;
	else if (keycode == 17)
		fdf->x_rotation += 0.2;
	else if (keycode == 3)
		fdf->y_rotation -= 0.2;
	else if (keycode == 5)
		fdf->y_rotation += 0.2;
	else if (keycode == 9)
		fdf->z_rotation -= 0.2;
	else if (keycode == 11)
		fdf->z_rotation += 0.2;
	do_calculations(fdf, 1);
}

void	apply_rotation(t_fdf *fdf, t_point *a)
{
	x_rotation(a, fdf->x_rotation);
	y_rotation(a, fdf->y_rotation);
	z_rotation(a, fdf->z_rotation);
}

void	x_rotation(t_point *a, float angle)
{
	int old_y3;
	int old_z3;

	old_y3 = a->y3;
	old_z3 = a->z3;
	a->y3 = old_y3 * cos(angle) + old_z3 * sin(angle) + 300 ;
	a->z3 = -old_y3 * sin(angle) + old_z3 * cos(angle) + 300;
}

void	y_rotation(t_point *a, float angle)
{
	int old_x3;
	int old_z3;

	old_x3 = a->x3;
	old_z3 = a->z3;
	a->x3 = old_x3 * cos(angle) + old_z3 * sin(angle);
	a->z3 = -old_x3 * sin(angle) + old_z3 * cos(angle);
}

void	z_rotation(t_point *a, float angle)
{
	int old_x3;
	int old_y3;

	old_x3 = a->x3;
	old_y3 = a->y3;
	a->x3 = old_x3 * cos(angle) - old_y3 * sin(angle);
	a->y3 = old_x3 * sin(angle) + old_y3 * cos(angle);
}