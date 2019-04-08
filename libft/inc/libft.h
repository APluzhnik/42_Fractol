/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:08:34 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 12:58:59 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Lib
*/
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

/*
** Inc
*/
# include "color.h"

/*
** Def
*/
# define BUFF_SIZE	32
# define FD_MAX		4864
# define WIN_W		1500
# define WIN_H		1000
# define MAX_ITER	300
# define THREADS	8
# define THR_WIDTH	150

# define CHECK(x) if (!x) return (-1);
# define SQR(x)	x * x
/*
** Struct
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Mem
*/
void				*ft_memset(void *s, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** Str
*/
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strlchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *str, char c);

/*
** Nbr
*/
size_t				ft_nbrlen(int num);

/*
** Conv
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Check
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/*
** Out
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Lst
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstsplit(char const *s, char c);
void				*ft_lstfold(t_list *lst, void *(*f)(const void *,
			const void*, size_t));

/*
** Syst
*/
void				ft_swap(void *a, void *b);
void				die(char *error);

/*
** Read
*/
int					get_next_line(const int fd, char **line);
int					ft_wordcount(const char *s, char c);
char				*ft_wordfound(const char *s, char c, int *i);

#endif
