/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:47 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:48:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	change_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == 15)
		fdf->x_rotation -= 0.261799;
	else if (keycode == 17)
		fdf->x_rotation += 0.261799;
	else if (keycode == 3)
		fdf->y_rotation -= 0.261799;
	else if (keycode == 5)
		fdf->y_rotation += 0.261799;
	else if (keycode == 9)
		fdf->z_rotation -= 0.261799;
	else if (keycode == 11)
		fdf->z_rotation += 0.261799;
	do_calculations(fdf, 1);
}

void	apply_rotation(t_fdf *fdf, t_point *a)
{
	x_rotation(fdf, a);
	y_rotation(fdf, a);
	z_rotation(fdf, a);
}

void	x_rotation(t_fdf *fdf, t_point *a)
{
	int old_y2;
	int old_z2;

	old_y2 = a->y2;
	old_z2 = a->z2;
	a->y2 = old_y2 * cos(fdf->x_rotation) + old_z2 * sin(fdf->x_rotation);
	a->z2 = -old_y2 * sin(fdf->x_rotation) + old_z2 * cos(fdf->x_rotation);
}

void	y_rotation(t_fdf *fdf, t_point *a)
{
	int old_x2;
	int old_z2;

	old_x2 = a->x2;
	old_z2 = a->z2;
	a->x2 = old_x2 * cos(fdf->y_rotation) + old_z2 * sin(fdf->y_rotation);
	a->z2 = -old_x2 * sin(fdf->y_rotation) + old_z2 * cos(fdf->y_rotation);
}

void	z_rotation(t_fdf *fdf, t_point *a)
{
	int old_x2;
	int old_y2;

	old_x2 = a->x2;
	old_y2 = a->y2;
	a->x2 = old_x2 * cos(fdf->z_rotation) - old_y2 * sin(fdf->z_rotation);
	a->y2 = old_x2 * sin(fdf->z_rotation) + old_y2 * cos(fdf->z_rotation);
}
