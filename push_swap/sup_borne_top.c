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



void sup_borne_to_top(t_ps_list **list, int borne)
{
    int index_rotate;
    int index_reverse;
    int nbre;
    

    nbre = count_pile(*list);
    index_rotate = index_rot_superieur(*list, borne);
    index_reverse = index_rev_superieur(*list, borne);
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

void inf_borne_to_top(t_ps_list **list, int borne)
{
    int index_rotate;
    int index_reverse;
    int nbr;

    nbr = count_pile(*list);
    index_rotate = index_rot_petit(*list, borne);
    index_reverse = index_rev_petit(*list, borne);
    if (index_rotate < (nbr - index_reverse))
    {
        while(index_rotate > 0)
        {
            ra(list);
            index_rotate--;
        }
    } else
    {
        while(index_reverse < nbr)
        {
            rra(list);
            index_reverse++;
        }
    }
}