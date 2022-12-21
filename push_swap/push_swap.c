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

void print_list(t_ps_list *list)
{
    int i;

    i = 1;
    if (!list)
        return ;
    while (list)
    {
        ft_printf("noeud %d : %d\n", i, list->nbr);
        list = list->next;
        i++;
    }
    ft_printf("----FIN DE LA LISTE----\n");
}

int main(int argc, char **argv)
{
    t_ps_list *pile_a;
    t_ps_list *pile_b;

    pile_a = NULL;
    pile_b = NULL;
    if (!(fill_list_verif(&pile_a, argc, argv)))
      //clean la list en verifiant si pas nulle
      return(-1);
    print_list(pile_a);
    push_x(&pile_b, &pile_a); 
    print_list(pile_a);
    print_list(pile_b);


	return (0);
}

