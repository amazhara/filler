/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worck_with_figur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:31:47 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/29 14:51:17 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		manhattan_distance(t_filler *f, int mx, int my)
{
	int		new;
	int		check;
	int		x;
	int		y;

	x = -1;
	y = -1;
	new = 0;
	while (f->map[++y])
	{
		x = -1;
		while (f->map[y][++x])
		{
			if (f->map[y][x] == 'x' || f->map[y][x] == 'X')
				check = ft_modul(mx, x) + ft_modul(my, y);
			if (check > new)
				new = check;
		}
	}
	if (new < f->manh || f->manh == 0)
	{
		f->manh = new;
		f->save[0] = f->hold[0];
		f->save[1] = f->hold[1];
		return (true);
	}
	return (false);
}

int		check_include(t_filler *f, t_coord *c)
{
	int	x;
	int	y;
	int	check;
	int	uncheck;

	x = -1;
	y = -1;
	check = 0;
	uncheck = 0;
	if (c->y + f->p.y < 0 || c->y + f->p.y > f->m.y
	|| c->x + f->p.x < 0 || c->x + f->p.x > f->m.x)
		return (false);
	while (f->fig[++y])
	{
		x = -1;
		while (f->fig[y][++x])
		{
			if (f->fig[y][x] == '*' && (f->map[c->y + y][c->x + x] == 'O'
			|| f->map[c->y + y][c->x + x] == 'o'))
			{
				f->hold[0] = c->y;
				f->hold[1] = c->x;
				check += 1;
			}
			if (f->fig[y][x] == '*' && (f->map[c->y + y][c->x + x] == 'x'
				||f->map[c->y + y][c->x + x] == 'X'))
				++uncheck;
		}
	}
	if (check == 1 && uncheck == 0 && manhattan_distance(f, f->hold[1], f->hold[0]))
		return (true);
	f->hold[0] = 0;
	f->hold[1] = 0;
	return (false);
}

void	worck_with_figur(t_filler *f)
{
	t_coord	c;
	int		stop;

	c.x = -1;
	c.y = -1;
	while (f->map[++c.y])
	{
		c.x = -1;
		while (f->map[c.y][++c.x])
			check_include(f, &c);
	}
	f->hold[0] = 0;
	f->hold[0] = 0;
	f->manh = 0;
}