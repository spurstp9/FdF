#ifndef FDF_H

# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_map_line
{
	int					*tab;
	int					*color;
	struct s_map_line	*prev;
	struct s_map_line	*next;
}						t_map_line;

typedef struct			s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlx_data;

typedef struct			s_map
{
	int					nbcol;
	int					nbline;
	t_map_line			*list;
}						t_map;

typedef struct			s_fdf
{
	t_mlx_data			mlx;
	t_map				map;
	float				zoom;
	int					altitude;
	int					x_shift;
	int					y_shift;
	char				proj;
}						t_fdf;

int		add_to_list(t_fdf *fdf, char **stock);
int		check_map(int fd, t_fdf *fdf);
int		deal_nb_col(t_fdf *fdf, char **stock);
void	display_menu(t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	draw_segment(t_fdf *fdf, t_point a, t_point b);
int		free_check_var(char **line, char ***stock, int len, int ret);
int		free_map_lines(t_fdf *fdf);
void	ft_display(t_fdf *fdf);
int		ft_fdf(char *map_path);
int		get_data(t_fdf *fdf,t_map_line *new, char **stock);
void	get_point_on_the_right(t_fdf *fdf, t_map_line *line, t_point a, t_point *b);
void	get_point_under(t_fdf *fdf, t_map_line *line, t_point a, t_point *b);
void	init_map(t_fdf *fdf);
void	iso(t_point *p);
int		key_hook(int keycode, void *param);
int		print_line(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_case1(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_case2(t_mlx_data *data, t_point p1, t_point p2);
void	print_tab(t_fdf *fdf);
int		split_line(char **line, char **tmp, char ***stock);
void	swap_points(t_point *a, t_point *b);

#endif