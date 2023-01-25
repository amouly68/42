/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:24:55 by amouly            #+#    #+#             */
/*   Updated: 2023/01/25 13:24:52 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_error(int argc, char **argv)
{
    int     len;
    
    if (argc != 2)
    {
        ft_printf("Error\nNombre d'arguments invalide\n");
        return (0);
    }
    len = ft_strlen(argv[1]) - 1;
    if (argv[1][len] != 'r' || argv[1][len - 1] != 'e'
        || argv[1][len - 2] != 'b' || argv[1][len - 3] != '.')
    {
        ft_printf("Error\nArgument invalide\n");
        return (0);
    }   
    return (1);
}