/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:12:30 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/30 14:01:03 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	choose_player(t_filler *f)
// {

// }

void	continue_malloc_f_m(t_filler *f, int x, int y)
{
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

	i = 0;
	y = 0;
	while (f->line[i] && f->line[i++] != ' ')
		if (f->line[i] == ' ')
		{
			if (y == 0)
				y = ft_atoi(&f->line[++i]);
			else
				x = ft_atoi(&f->line[++i]);
		}
	continue_malloc_f_m(f, x, y);
}

void	pars_map(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (get_next_line(0, &f->line))
	{
		(f->circle) && (f->fig[++j] = ft_strdup(f->line));
		(f->line[0] == '0') && (f->map[++i] = ft_strdup(f->line + 4));
		if (ft_strstr(f->line, f->argv[0]))
			f->player = ft_strstr(f->line, "p1") ? 1 : 2;
		if (f->line[0] == 'P')
			malloc_f_m(f);
		free(f->line);
		if (f->circle && !--f->circle)
		{
			(f->player == 2) ? worck_with_figur_p2(f) : worck_with_figur(f);
			ft_printf("%d %d\n", f->save[0], f->save[1]);
			free_f_m(f, &i, &j);
		}
	}
}
