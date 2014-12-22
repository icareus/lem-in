/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 01:46:16 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/22 22:16:09 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define IS_POS(x)		(x > 0 ? 1 : 0)
# define IS_NEG(x)		(x < 0 ? 1 : 0)
# define ABS(x)			(x > 0 ? x : -x)
# define PRINT_SET		"%cdis"

# include "get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int			ft_atoi(const char *str);
void		ft_anything(void);
void		ft_bzero(void *s, size_t n);
int			ft_count_words(const char *s, char separator);
char		*ft_itoa(int n);
int			ft_intlen(int n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
void		*ft_memdup(void *src, int size);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		ft_memslide(void *src, size_t slen, size_t maxlen);
void		*ft_memset(void *b, int c, size_t len);
int			ft_nbrlen(int i);
int			ft_printf(char *form, ...);
void		ft_putchar(char c);
int			ft_putflt(float f);
void		ft_putnbr(int i);
void		ft_putendl(char *str);
void		ft_putendl_fd(char *str, int fd);
int			ft_putstr(const char *s);
void		ft_putstr_fd(const char *s, int fd);
void		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
size_t		ft_strlchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		ft_strslide(char *str, int slen);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strtrim(char const *s);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_strsplit(const char *s, char c);
int			*ft_strsplittoint(char const *str, char c);
int			ft_isalpha(int c);
void		ft_ndl(int n);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		ft_lst_foreach(t_list *first, void (*f)());
t_list		*ft_lst_push(t_list *first, void *data);
void		ft_lst_rec_free(t_list *first);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_strequ(char const *s1, char const *s2);

#endif
