/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:08:16 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

long long	ft_long_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	num;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	num = num * neg;
	return (num);
}

int	check_int(long long nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
		return (0);
	return (1);
}

int	check_error(char *argv)
{
	int	i;

	if (!(check_int(ft_long_atoi(argv))))
		return (0);
	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && (argv[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

int	check_list(t_ps_list *list)
{
	t_ps_list	*next;
	t_ps_list	*head;
	int			current;

	head = list;
	while (head->next)
	{
		next = head->next;
		current = head->nbr;
		while (head->next)
		{
			if (current == (head->next)->nbr)
				return (0);
			head = head->next;
		}
		head = next;
	}
	return (1);
}
