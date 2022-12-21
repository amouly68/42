/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 09:50:55 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

long long	ft_long_atoi(const char *str)
{
	int	i;
	int	neg;
	long long	num;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9' ))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}		
	num = num * neg;
	return (num);
}

int check_int(long long nbr)
{
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    return (1);
}

int check_error(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        if (!(check_int(ft_long_atoi(argv[i]))))
            return (0);
        j = 0;
        while (argv[i][j])
        {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && (argv[i][j] != '-'))
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}



