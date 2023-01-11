/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 09:49:30 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct l_list
{
	int				nbr;
	struct l_list	*next;
}	t_ps_list;

//fill_list.c
int fill_list(t_ps_list **list, int nbr);
int fill_list_verif(t_ps_list **list, int argc, char **argv);
//check_error
int check_list(t_ps_list *list);
long long	ft_long_atoi(const char *str);
int check_int(long long nbr);
int check_error(int argc, char **argv);
//swap.c
void    sa(t_ps_list **list);
void    sb(t_ps_list **list);
void	ss(t_ps_list **list_a, t_ps_list **list_b);
//push
void    pa(t_ps_list **list_a, t_ps_list **list_b);
void    pb(t_ps_list **list_b, t_ps_list **list_a);
void    push_silent(t_ps_list **list_a, t_ps_list **list_b);
//rotate
void    ra(t_ps_list **list);
void    rotate(t_ps_list **list);
void    rb(t_ps_list **list);
void    rr(t_ps_list **list_a, t_ps_list **list_b);
//reverse
t_ps_list   *ft_getlast(t_ps_list *list);
t_ps_list   *ft_getprelast(t_ps_list *list);
void    rra(t_ps_list **list);
void    rrb(t_ps_list **list);
void    rrr(t_ps_list **list_a, t_ps_list **list_b);
//less_than_five
void sort_three_numbers_a(t_ps_list **list_a);
void sort_three_numbers_inv_a(t_ps_list **list_a);
void less_than_four(t_ps_list **list_a, int argc);
int four_to_fifteen(t_ps_list **list_a, t_ps_list **list_b, int argc);
//print_list
void print_list(t_ps_list *list);
void print_both_list(t_ps_list *list_1, t_ps_list *list_2);
//find_max_min
t_ps_list *find_max(t_ps_list *list);
int index_max(t_ps_list *list);
t_ps_list *find_min(t_ps_list *list);
int index_min(t_ps_list *list);
//max_min_to_top
int count_pile(t_ps_list    *list);
void max_to_top_a(t_ps_list **list);
void min_to_top_a(t_ps_list **list);
void max_to_top_b(t_ps_list **list);
void max_to_top_silent(t_ps_list **list);
//more_than_fifteen
int more_than_fifteen(t_ps_list **list_a, t_ps_list **list_b);
int more_than_fifteen_v2(t_ps_list **list_a, t_ps_list **list_b, int argc, int median);
int more_than_fifteen_v3(t_ps_list **list_a, t_ps_list **list_b, int argc);
//a_to_b
void a_to_b(t_ps_list **list_a, t_ps_list **list_b);
//a_to_b_v2
void a_to_b_v2(t_ps_list **list_a, t_ps_list **list_b, int grand, int median);
void a_to_b_bis(t_ps_list **list_a, t_ps_list **list_b, int quarter);
// tab
void sort_tab(int *tab, int length);
int midd_value(t_ps_list *list);
int prem_quarter(t_ps_list *list);
int third_quarter(t_ps_list *list);
//index_grand_petit
int index_rev_petit(t_ps_list *list, int median);
int index_rev_grand(t_ps_list *list, int median);
int index_rot_petit(t_ps_list *list, int median);
int index_rot_grand(t_ps_list *list, int median);
//grand_petit_top
void grand_to_top(t_ps_list **list, int middle);
void petit_to_top(t_ps_list **list, int middle);
//sup_borne_to_top
void sup_borne_to_top(t_ps_list **list, int borne);
void inf_borne_to_top(t_ps_list **list, int borne);
//index borne
int index_rev_inferieur(t_ps_list *list, int borne);
int index_rot_inferieur(t_ps_list *list, int borne);
int index_rev_superieur(t_ps_list *list, int borne);
int index_rot_superieur(t_ps_list *list, int borne);
//decile
int decile_1(t_ps_list *list);
int decile_2(t_ps_list *list);
int decile_3(t_ps_list *list);
int decile_4(t_ps_list *list);
int decile_5(t_ps_list *list);
int decile_6(t_ps_list *list);
int decile_7(t_ps_list *list);
int decile_8(t_ps_list *list);
int decile_9(t_ps_list *list);

#endif
