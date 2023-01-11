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

int decile_1(t_ps_list *list)
{
    int nbr;
    int i;
    int *tab;
    int decile;

    i = 0;
    nbr = count_pile(list);
    tab = malloc(sizeof(int) * nbr);
    if (tab == NULL)
        return(-1);
    while(list)
    {
        tab[i] = list->nbr;
        list = list->next;
        i++;
    }
    sort_tab(tab, nbr);
    decile = tab[(nbr / 10) * 1];
    free(tab);
    return (decile);
}

int decile_2(t_ps_list *list)
{
    int nbr;
    int i;
    int *tab;
    int decile;

    i = 0;
    nbr = count_pile(list);
    tab = malloc(sizeof(int) * nbr);
    if (tab == NULL)
        return(-1);
    while(list)
    {
        tab[i] = list->nbr;
        list = list->next;
        i++;
    }
    sort_tab(tab, nbr);
    decile = tab[(nbr / 10) * 2];
    free(tab);
    return (decile);
}

int decile_3(t_ps_list *list)
{
    int nbr;
    int i;
    int *tab;
    int decile;

    i = 0;
    nbr = count_pile(list);
    tab = malloc(sizeof(int) * nbr);
    if (tab == NULL)
        return(-1);
    while(list)
    {
        tab[i] = list->nbr;
        list = list->next;
        i++;
    }
    sort_tab(tab, nbr);
    decile = tab[(nbr / 10) * 3];
    free(tab);
    return (decile);
}

int decile_4(t_ps_list *list)
{
    int nbr;
    int i;
    int *tab;
    int decile;

    i = 0;
    nbr = count_pile(list);
    tab = malloc(sizeof(int) * nbr);
    if (tab == NULL)
        return(-1);
    while(list)
    {
        tab[i] = list->nbr;
        list = list->next;
        i++;
    }
    sort_tab(tab, nbr);
    decile = tab[(nbr / 10) * 4];
    free(tab);
    return (decile);
}

int decile_5(t_ps_list *list)
{
    int nbr;
    int i;
    int *tab;
    int decile;

    i = 0;
    nbr = count_pile(list);
    tab = malloc(sizeof(int) * nbr);
    if (tab == NULL)
        return(-1);
    while(list)
    {
        tab[i] = list->nbr;
        list = list->next;
        i++;
    }
    sort_tab(tab, nbr);
    decile = tab[(nbr / 10) * 5];
    free(tab);
    return (decile);
}