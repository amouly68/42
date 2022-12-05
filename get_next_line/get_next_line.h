/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2022/12/05 15:22:45 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#  include <stdlib.h>
#  include <unistd.h>

typedef struct l_list
{
	char 			*str;
	struct l_list	 *next;
} s_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(s_list **list, s_list *new);
void	fill_node(s_list **stock, int fd);
int		check_new_line(s_list *list, int *count);
void	print_list(s_list *list);
char	*extract_line(s_list *stock, int *count);

#endif
