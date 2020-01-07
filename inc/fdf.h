#ifndef FDF_H

# define FDF_H
# include <mlx.h>
# include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx_data;

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		key_hook(int key, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		print_line(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_case1(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_case2(t_mlx_data *data, t_point p1, t_point p2);
void	swap_points(t_point *a, t_point *b);

#endif