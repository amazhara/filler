/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:29:19 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/29 13:33:47 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H
#include <stdlib.h>
#include <unistd.h>
#include "printf/libft/libft.h"
#include "printf/ft_printf.h"

typedef struct		s_coord
{
	int		x;
	int		y;
}					t_coord;

typedef struct		s_filler
{
	char	*line;
	char	**map;
	char	**fig;
	int		hold[2];
	int		save[2];
	int		manh;
	int		tmp;
	int		circle;
	t_coord	m;
	t_coord	p;
}					t_filler;

void		pars_map(t_filler *f);
void		worck_with_figur(t_filler *f);
#endif