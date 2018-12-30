/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:32:28 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/29 22:00:01 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int ac, char *av[])
{
	t_filler	f;

	ft_bzero(&f, sizeof(t_filler));
	(void)ac;
	f.argv = av;
	pars_map(&f);
}
