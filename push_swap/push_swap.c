/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 11:52:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


int main(int argc, char **argv)
{
    int i;
    t_ps_list *list;

    list = NULL;
    //ft_printf("adress de list =  %p\n", &list);
    i = 1;
    while (i < argc )
    {
      //  ft_printf("avant fill list i = %d et argv[i] = %s\n", i, argv[i]);
        fill_list(&list, ft_atoi(argv[i]));
      //  print_list(list);
        //ft_printf("arg[%d] :  %d\n", i, ft_atoi(argv[i]));        
        i++;
    }
    print_list(list);
	return (0);
}

