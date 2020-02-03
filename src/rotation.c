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

void	apply_rotation(t_fdf *fdf, t_point *a, t_rot_data *r)
{
	int old_x2;
	int old_y2;
	int old_z2;

	old_x2 = a->x2 - ((fdf->x_max - fdf->x_min) / 2);
	old_y2 = a->y2 - ((fdf->y_max - fdf->y_min) / 2);
	old_z2 = a->z2;
	a->x2 = old_x2 * r->C * r->E - old_y2 * r->C * r->F + r->D * old_z2;
	a->y2 = old_x2 * r->BD * r->E + old_x2 * r->A * r->F - old_y2 * r->BD * r->F + old_y2 * r->A * r->E - old_z2 * r->B * r->C;
	a->z2 = -r->AD * r->E * old_x2 + r->B * r->F * old_x2 + r->AD * r->F * old_y2 + r->B * r->E * old_y2 + r->A * r->C * old_z2;
}

void	set_rot_data(t_fdf *fdf, t_rot_data *r)
{
	r->A = cos(fdf->x_rotation);
	r->B = sin(fdf->x_rotation);
	r->C = cos(fdf->y_rotation);
	r->D = sin(fdf->y_rotation);
	r->E = cos(fdf->z_rotation);
	r->F = sin(fdf->z_rotation);
	r->AD = r->A * r->D;
	r->BD = r->B * r->D;
}
