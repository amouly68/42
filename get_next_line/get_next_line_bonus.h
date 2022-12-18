I
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2022/12/14 11:10:48 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45 
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct l_list
{
	char			*str;
	struct l_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **list, t_list *new);
int		fill_node(t_list **stock, int fd);
int		check_new_line(t_list *list);
int		count_char_line(t_list *list);
void	print_list(t_list *list);
char	*extract_line(t_list *stock, int count);
char	*trim_str(char *str);
void	trim_list(t_list **stock);
int		newline_in_node(t_list *node);
void	print_list(t_list *list);
int		clean_stock(t_list **list, int fd, char *line);

#endif
