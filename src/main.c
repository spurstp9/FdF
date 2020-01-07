#include "../inc/fdf.h"
#include <stdio.h>

int main(void)
{
	t_mlx_data	data;
	t_point p1;
	t_point p2;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "test");
	p1.x = 200;
	p1.y = 0;

	p2.x = 0;
	p2.y = 500;
	print_line(&data, p1, p2);
	mlx_loop(data.mlx_ptr);
	printf("OK\n");
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
 {
 	t_point p;

 	(void)button;
 	printf("Mouse hook\n");
 	p.x = x;
 	p.y = y;
 	param = &p;
 	return (1);
 }

int	key_hook(int key, void *param)
 {
 	(void)key;
 	(void)param;
 	printf("Key hook\n");
 	return (1);
 }