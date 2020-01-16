#include "../inc/fdf.h"

int	check_map(int fd, t_fdf *fdf)
{
	char *line;
	char *tmp;
	char **stock;

	line = NULL;
	tmp = NULL;
	stock = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!split_line(&line, &tmp, &stock))
			return (free_check_var(&line, &stock, fdf->map.nbcol, 0));
		if (!deal_nb_col(fdf, stock))
			return (free_check_var(&line, &stock, fdf->map.nbcol, 0));
		if (!add_to_list(fdf, stock))
			return (free_check_var(&line, &stock, fdf->map.nbcol, 0));
	}
	return (free_check_var(&line, &stock, fdf->map.nbcol, 1));
}

int	split_line(char **line, char **tmp, char ***stock)
{
	*tmp = *line;
	if (!(*line = ft_strtrim(*line)))
		return (0);
	ft_strdel(tmp);
	if (!(*stock = ft_split(*line, " ")))
		return (0);
	return (1);
}

int	deal_nb_col(t_fdf *fdf, char **stock)
{
	int res;
	int i;

	res = 0;
	i = 0;
	if (fdf->map.nbcol == -1)
	{
		while (stock[i])
		{
			res++;
			i++;
		}
		(fdf->map.nbcol) = res;
		return (1);
	}
	else
	{
		while (stock[i])
		{
			res++;
			i++;
		}
	}
	return ((res == fdf->map.nbcol));
}

int	get_data(t_fdf *fdf, t_map_line *new, char **stock)
{
	int i;

	i = 0;
	if (!((new->tab) = (t_point*)malloc(sizeof(t_point) * fdf->map.nbcol)))
		return (0);
	while (i < fdf->map.nbcol)
	{
		(new->tab[i]).x = i;
		(new->tab[i]).y = fdf->map.nbline - 1;
		(new->tab[i]).z = ft_atoi(stock[i]);
		i++;
	}
	return (1);
}

void print_tab(t_fdf *fdf)
{
	int i;
	t_map_line *line;

	line = fdf->map.list;
	while (line)
	{
		i = 0;
		while (i < fdf->map.nbcol)
		{
			printf("%d,%d  ", line->tab[i].z, line->tab[i].color);
			// if (line->tab[i].z < 10)
			// 	printf(" ");
			i++;
		}
		printf("\n");
		line = line->next;
	}
}

int	add_to_list(t_fdf *fdf, char **stock)
{
	t_map_line *last;
	t_map_line *new;

	(fdf->map.nbline)++;
	last = fdf->map.list;
	if (!(new = (t_map_line*)malloc(sizeof(t_map_line) * fdf->map.nbcol)))
		return (0);
	while (last && last->next)
		last = last->next;
	if (!get_data(fdf, new, stock))
		return (0);
	new->next = NULL;
	if (fdf->map.list == NULL)
	{
		fdf->map.list = new;
		fdf->map.list->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
	return (1);
}