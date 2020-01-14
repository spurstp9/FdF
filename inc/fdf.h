#ifndef FDF_H

# define FDF_H
# define WIN_HEIGHT 738
# define WIN_WIDTH 1268
# define WHITE 0xFFFFFF
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
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
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
	float				x_rotation;
	float				y_rotation;
	float				z_rotation;
	char				proj;
}						t_fdf;

int		add_to_list(t_fdf *fdf, char **stock);
void	apply_proj(t_fdf *fdf, t_point *a, t_point *b);
void	apply_zoom_altitude_rotation(t_fdf *fdf, t_point *a, t_point *b);
void	cabinet(t_point *p);
void	change_altitude_zoom_shift(t_fdf *fdf, int keycode);
void	change_rotation(t_fdf *fdf, int keycode);
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
void	init_fdf(t_fdf *fdf, char proj);
void	iso(t_point *p);
int		key_hook(int keycode, void *param);
int		print_line_img(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_img_case1(t_mlx_data *data, t_point p1, t_point p2);
int		print_line_img_case2(t_mlx_data *data, t_point p1, t_point p2);
void	print_tab(t_fdf *fdf);
void	reset_fdf(t_fdf *fdf, char proj);
int		split_line(char **line, char **tmp, char ***stock);
void	swap_points(t_point *a, t_point *b);
void	x_rotation(t_point *a, float angle);
void	y_rotation(t_point *a, float angle);
void	z_rotation(t_point *a, float angle);

#endif