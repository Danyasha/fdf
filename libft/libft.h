/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:02:41 by btorp             #+#    #+#             */
/*   Updated: 2019/04/06 02:11:19 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 500

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <string.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				get_next_line(const int fd, char **line);
size_t			ft_strlcat(char *s1, char const *s2, size_t num);
void			*ft_memmove(void *dst, const void *src, size_t n);
int				ft_atoi(const char *str);
void			ft_bzero(void *c, size_t num);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dst, const void *src, int ch, size_t n);
void			*ft_memchr(const void *memptr, int val, size_t num);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *ptr, int value, size_t num);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *str, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *d, const char *s);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *s1, const char *s2, size_t num);
int				ft_strncmp(const char *s1, const char *s2, size_t num);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strncpy(char *d, const char *s, size_t n);
int				ft_memcmp(const void *buf, const void *buf2, size_t count);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap (t_list *lst, t_list *(*f)(t_list *elem));
void			ft_swap(int *a, int *b);
int				ft_iswhitespase(char s);
int				ft_strisnumeric(const char *s);
char			*ft_strtolower(char *s);
char			*ft_strtoupper(char *s);
char			*ft_strreplacechr(const char *src, char to, char what);
int				ft_findch(char *s, char c);
char			*ft_strjoinfree(char *s1, char *s2);

#endif
