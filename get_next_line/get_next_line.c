/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/04 13:35:39 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_curser(char *str, ret)
{
	int	a;
	char * ret;

	a = 0;
	while (str[a] != '\n' && str[a] != '\0')



}


char	*get_next_line(int fd)
{
	static char *stock;
	char	*val_return;

	if (stock != NULL)
	{
		
	
	}		
	if (read (fd, stock, BUFFER_SIZE) > 0)
	{
		
	
	}

}
