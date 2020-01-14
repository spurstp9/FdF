#include "../inc/fdf.h"

int	 print_line_img(t_mlx_data *data, t_point p1, t_point p2)
{
	int dx;
	int dy;

	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	if (dx >= dy)
		print_line_img_case1(data, p1, p2);
	else
		print_line_img_case2(data, p1, p2);
	return (1);
}

int	print_line_img_case1(t_mlx_data *data, t_point p1, t_point p2)
{
	int e;
	int dx;
	int dy;
	int y_incr;

	if (p1.x > p2.x)
		swap_points(&p1, &p2);
	// printf("(%d, %d), (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	dx = p2.x - p1.x;
	dy = ft_abs(p2.y - p1.y);
	y_incr = (p2.y >= p1.y) ? 1 : -1;
	e = (2 * dy) + dx;
	while (p1.x <= p2.x)
	{
		e -= (2 * dy);
		if (e <= 0)
		{
			p1.y += y_incr;
			e += (2 * dx);
		}
		// printf("Indice première case : %d\n", p1.x * 4 + data->size_line * p1.y);
		if (0 <= p1.x && p1.x < WIN_WIDTH && 0 <= p1.y && p1.y < WIN_HEIGHT)
		{
			(data->img_data)[p1.x * 4 + data->size_line * p1.y] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 1] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 2] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 3] = 0;
		}
		p1.x++;
	}
	return (1);
}

int	print_line_img_case2(t_mlx_data *data, t_point p1, t_point p2)
{
	int dx;
	int dy;
	int e;
	int x_incr;

	if (p1.y > p2.y)
		swap_points(&p1, &p2);
	// printf("(%d, %d), (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	x_incr = (p1.x <= p2.x) ? 1 : -1;
	dx = ft_abs(p2.x - p1.x);
	dy = p2.y - p1.y;
	e = (2 * dx) + dy;
	while (p1.y <= p2.y)
	{
		e -= (2 * dx);
		if (e <= 0)
		{
			p1.x += x_incr;
			e += (2 * dy);
		}
		// printf("Indice première case : %d\n", p1.x * 4 + data->size_line * p1.y);
		if (0 <= p1.x && p1.x < WIN_WIDTH && 0 <= p1.y && p1.y < WIN_HEIGHT)
		{
			(data->img_data)[p1.x * 4 + data->size_line * p1.y] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 1] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 2] = 0xFF;
			(data->img_data)[p1.x * 4 + data->size_line * p1.y + 3] = 0;
		}
		p1.y++;
	}
	return (1);
}

void	swap_points(t_point *a, t_point *b)
{
	t_point tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	tmp.z = a->z;
	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
	b->x = tmp.x;
	b->y = tmp.y;
	b->z = tmp.z;
}