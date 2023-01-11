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



void grand_to_top(t_ps_list **list, int middle)
{
    int index_rotate;
    int index_reverse;
    int nbre;
    

    nbre = count_pile(*list);
    index_rotate = index_rot_grand(*list, middle);
    index_reverse = index_rev_grand(*list, middle);
    //ft_printf(" nbre d'elements dans A : %d et le premier element : %d\n", nbre, (*list)->nbr);
    //ft_printf(" index rotate : %d et index_reverse : %d\n", index_rotate, index_reverse);
        
    if (index_rotate < (nbre - index_reverse))
    {
        while(index_rotate > 0)
        {
            ra(list);
            index_rotate--;
        }
    }
    else 
    {
        while(index_reverse < nbre)
        {
            rra(list);
            index_reverse++;
        }
    }
}

void petit_to_top(t_ps_list **list, int middle)
{
    int index_rotate;
    int index_reverse;
    int i;
    int nbr;

    nbr = count_pile(*list);
    index_rotate = index_rot_petit(*list, middle);
    index_reverse = index_rev_petit(*list, middle);
    i = 0;
   if (index_rotate < (nbr - index_reverse))
    {
       // ft_printf("par le haut en %d coups\n", index_rotate);
        while(index_rotate > 0)
        {
            ra(list);
            index_rotate--;
        }
    } else
    {
        //ft_printf("par le bas en %d coups\n", nbr - index_reverse);
        while(index_reverse < nbr)
        {
            rra(list);
            index_reverse++;
        }
    }
}

/*void grand_to_top(t_ps_list *list, int middle, int nbr)
{
    int index_rotate;
    int index_reverse;
    t_ps_list *head;
    int i;

    head = list;
    index_rotate = 0;
    index_reverse = 0;
    i = 0;
    while(list)
    {
        if (list->nbr > middle)
            break ;
        index_rotate++;
        list = list -> next;
    }
    while(head)
    {
        if (head->nbr > middle)
            index_reverse = i;
        i++;
        head = head -> next;
    }
    ft_printf("nbr : %d\n", nbr);
    ft_printf("index rotate : %d\n", index_rotate);
    ft_printf("index reverse : %d\n", index_reverse);
    if (index_rotate < (nbr - index_reverse))
        ft_printf("par le haut en %d coups\n", index_rotate);
    {
        while(index_rotate > 0)
        {
            ra(&list);
            index_rotate--;
        }
    }
     else 
        ft_printf("par le bas en %d coups\n", nbr - index_reverse);
    {
        while(index_reverse < nbr)
        {
            rra(&list);
            index_reverse++;
        }
    }
}
*/