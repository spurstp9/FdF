#include "../inc/fdf.h"

int	check_map(int fd, t_fdf *fdf)
{
	char *line;
	char *tmp;
	char **stock;
	int	ret;

	line = NULL;
	tmp = NULL;
	stock = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!check_line(line))
			return (free_check_var(&line, &stock, fdf->nbcol, -1));
		if (!split_line(&line, &tmp, &stock))
			return (free_check_var(&line, &stock, fdf->nbcol, -1));
		if (!deal_nb_col(fdf, stock))
			return (free_check_var(&line, &stock, fdf->nbcol, -1));
		if (!add_to_tab(fdf, stock))
			return (free_check_var(&line, &stock, fdf->nbcol, -1));
	}
	return (free_check_var(&line, &stock, fdf->nbcol, ret));
}

int	check_line(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line != '-' && *line != '+' && !ft_isdigit(*line))
			return (0);
		if ((*line == '-' || *line == '+') && (!*(line + 1) || !ft_isdigit(*(line + 1))))
			return (0);
		line++;
	}
	return (1);
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

int	add_to_tab(t_fdf *fdf, char **stock)
{
	t_point *new;
	int i;
	int start;

	fdf->nbline++;
	fdf->total += fdf->nbcol;
	i = 0;
	start = fdf->nbcol * (fdf->nbline - 1);
	if (!(new = (t_point*)malloc(sizeof(t_point) * fdf->nbcol * fdf->nbline)))
		return (0);
	if (fdf->tab)
		ft_memcpy(new, fdf->tab, sizeof(t_point) * fdf->nbcol * (fdf->nbline - 1));
	i = 0;
	while (stock[i])
	{
		new[start + i].x = i;
		new[start + i].y = fdf->nbline - 1;
		new[start + i].z = ft_atoi(stock[i]);
		i++;
	}
	free(fdf->tab);
	fdf->tab = new;
	return (1);
}

int	deal_nb_col(t_fdf *fdf, char **stock)
{
	int res;
	int i;

	res = 0;
	i = 0;
	if (fdf->nbcol == -1)
	{
		while (stock[i])
		{
			res++;
			i++;
		}
		(fdf->nbcol) = res;
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
	return ((res == fdf->nbcol));
}

void print_tab(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->total)
	{
		printf("%d,%d  ", fdf->tab[i].z, fdf->tab[i].color);
		if (fdf->tab[i].z < 10)
				printf(" ");
		if ((i + 1) % fdf->nbcol == 0)
			printf("\n");
		i++;
	}
}