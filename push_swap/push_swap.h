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

void	print_list(t_ps_list *list);
int fill_list(t_ps_list **list, int nbr);
int fill_list_verif(t_ps_list **list, int argc, char **argv);
t_ps_list   *ft_getlast(t_ps_list *list);
t_ps_list   *ft_getprelast(t_ps_list *list);
void    swap_pile(t_ps_list **list);
void    push_x(t_ps_list **list_x, t_ps_list **list_y);
void    rotate_pile(t_ps_list **list);
void    rev_rotate_pile(t_ps_list **list);
long long	ft_long_atoi(const char *str);
int check_int(long long nbr);
int check_error(int argc, char **argv);

#endif
