/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:08:43 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 10:08:46 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_so_long	sl;

	if (!(check_error(argc, argv)))
		return (-1);
	init_sl(&sl);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s n'existe pas\n", argv[1]);
		return (-1);
	}
	if (!(parse_map(&sl, fd)))
		return (-1);
	ft_printf("%d\n", sl.steps);
	if (!(add_graphic(&sl)))
		return (-1);
	free(sl.tab);
	sl.tab = NULL;
	free_list(&(sl.map));
}
