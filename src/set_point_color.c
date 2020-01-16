#include "../inc/fdf.h"

void	set_point_color(t_fdf *fdf, t_point *a)
{
	t_gradient grad;

	grad.start.z = fdf->new_alt_min;
	grad.start.color = fdf->color;
	grad.finish.z = fdf->new_alt_max;
	grad.finish.color = 0xFFFFFF;
	a->color = get_gradient(grad, *a, 3);
}