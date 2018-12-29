/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:12:30 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/29 14:51:41 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>
int debugfd;

void	free_f_m(t_filler *f, int *i, int *j)
{
	char	*tmp;

	ft_double_free(f->map, 0);
	ft_double_free(f->fig, 0);
	tmp = 0;
	f->save[0] = 0;
	f->save[1] = 0;
	*i = -1;
	*j = -1;
}

void	malloc_f_m(t_filler *f)
{
	int		y;
	int		x;
	int		i;
	char	*tmp;

	i = 0;
	y = 0;
	while (f->line[i] && f->line[i++] != ' ')
	{
		if (f->line[i] == ' ')
		{
			if (y == 0)
				y = ft_atoi(&f->line[++i]);
			else
				x = ft_atoi(&f->line[++i]);
		}
	}
	if (f->line[1] == 'l')
	{
		f->m.y = y - 1;
		f->m.x = x - 1;
		f->map = ft_double_malloc(y, x);
	}
	if (f->line[1] == 'i')
	{
		f->p.y = y - 1;
		f->p.x = x - 1;
		f->fig = ft_double_malloc(y, x);
		f->circle = y + 1;
	}
}

void	pars_map(t_filler *f)
{
	int	i;
	int	j;
	int	fd;

	i = -1;
	j = -1;
	// fd = open("txt", O_RDONLY);
	while (get_next_line(0, &f->line))
	{
		if (f->circle)
			f->fig[++j] = ft_strdup(f->line);
		if (f->line[0] == '0')
			f->map[++i] = ft_strdup(f->line + 4);
		if (f->line[0] == 'P')
			malloc_f_m(f);
		free(f->line);
		if (f->circle && !--f->circle)
		{
			worck_with_figur(f);
			ft_printf("%d %d\n", f->save[0], f->save[1]);
			free_f_m(f, &i, &j);
		}
	}
}
