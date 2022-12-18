/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:30:15 by amouly            #+#    #+#             */
/*   Updated: 2022/12/18 11:37:31 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int destsize);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int destsize);
void			*ft_memset(void *b, int c, unsigned int len);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
int				ft_atoi(const char *str);
char			*ft_strnstr(const char *haystack, const char *needle,
					unsigned int len);
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *s1);
void			*ft_memmove(void *dest, const void *src, unsigned int len);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void			ft_striteri(char *s, void (*f) (unsigned int, char*));

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
//   AJOUT DE PRINTF

int				ft_putnbr_base(unsigned int nbr, char *base);
int				ft_putnbr_u_fd(unsigned int n, int fd);
int				ft_putnbr_long_base(unsigned long long int nbr, char *base);
int				ft_putpointer(unsigned long long int pointer);
int				ft_putstr_fd_printf(const char *s, int fd);
int				ft_count_num(long int n);
int				parse(const char c, va_list ptr, int *count);
int				ft_printf(const char *str, ...);
int				ft_putnbr_fd_printf(int n, int fd);
int				ft_putchar_fd_printf(char c, int fd);

// AJOUT DE GET NEXT LINE

typedef struct b_list
{
	char			*str;
	struct b_list	*next;
}					gnl_list;

char			*get_next_line(int fd);
int				fill_node(gnl_list **stock, int fd);
int				check_new_line(gnl_list *list);
int				count_char_line(gnl_list *list);
char			*extract_line(gnl_list *stock, int count);
char			*trim_str(char *str);
void			trim_list(gnl_list **stock);
int				newline_in_node(gnl_list *node);
int				clean_stock(gnl_list **list, int fd, char *line);
void			ft_lstadd_back_gnl(gnl_list **lst, gnl_list *new);

#endif
