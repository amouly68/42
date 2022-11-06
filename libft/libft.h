/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:30:15 by amouly            #+#    #+#             */
/*   Updated: 2022/11/06 10:56:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

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

#endif
