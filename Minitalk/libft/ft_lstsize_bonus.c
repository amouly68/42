/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:11:25 by amouly            #+#    #+#             */
/*   Updated: 2022/11/08 11:28:18 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			a;

	a = 0;
	if (lst == NULL)
		return (0);
	else if (lst->next == NULL)
		return (1);
	while (lst != NULL)
	{
		lst = lst->next ;
		a++;
	}
	return (a);
}
