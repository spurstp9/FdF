#include "../inc/fdf.h"

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
	{
		free_fdf((t_fdf*)param);
		exit(0);
	}
	else if (keycode == 13 || keycode == 1)
		change_altitude((t_fdf*)param, keycode);
	else if (keycode == 24 || keycode == 27)
		change_zoom((t_fdf*)param, keycode);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		change_shift((t_fdf*)param, keycode);
	else if (keycode == 6)
		reset_fdf((t_fdf*)param, ((t_fdf*)param)->proj);
	else if (keycode == 7)
		change_proj((t_fdf*)param);
	else if (keycode == 8 && ++(((t_fdf*)param)->color_code))
		change_color((t_fdf*)param);
	else if (keycode == 15 || keycode == 17 || keycode == 3 || keycode == 5
		|| keycode == 9 || keycode == 11)
		change_rotation((t_fdf*)param, keycode);
	ft_display((t_fdf*)param);
	return (1);
}