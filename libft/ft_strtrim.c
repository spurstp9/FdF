/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:42:50 by agardina          #+#    #+#             */
/*   Updated: 2019/04/24 14:01:11 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static void	get_ws_count(char const *s, int *start, int *end)
{
	int i;

	if (!s[0])
	{
		*start = 0;
		*end = 0;
	}
	else
	{
		i = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		*start = i;
		if (!s[i])
			*start = *end;
		else
		{
			i = (int)ft_strlen(s) - 1;
			while (i > *start && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
				i--;
			*end = i;
		}
	}
}

static void	fill_new_str(char const *s, char *new, int start, int end)
{
	int i;

	i = start;
	while (i <= end)
	{
		new[i - start] = s[i];
		i++;
	}
	new[end - start + 1] = '\0';
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	get_ws_count(s, &start, &end);
	if (start == end)
	{
		if ((new = (char*)malloc(sizeof(char))) == NULL)
			return (NULL);
		new[0] = '\0';
	}
	else
	{
		if ((new = (char*)malloc(sizeof(char)
								* (size_t)(end - start + 2))) == NULL)
			return (NULL);
		fill_new_str(s, new, start, end);
	}
	return (new);
}
