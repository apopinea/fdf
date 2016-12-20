/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:05:46 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/22 15:00:04 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# include <string.h>
# include <errno.h>
# define ABS(x) ((x < 0) ? -x : x)
# define BUFF_SIZE 1000
# define PI 3.14159265359

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** i : nombre de lignes
** j : nombre de colonnes
*/

typedef struct		s_matrix
{
	double			**mat;
	size_t			i;
	size_t			j;
}					t_matrix;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int n);
int					ft_atoi(char *str);
int					ft_atoi_next(char *str, int *i);
double				ft_atoi_f(char *str);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_getstr(int size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
long int			ft_pow(int nb, unsigned int p);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_getstr(int size);
void				*ft_memdup(const void *s1, size_t l);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst);
void				ft_lstdel(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_lecture_f(char *file, size_t i, size_t max);
void				*ft_rememalloc(void *s, size_t l, size_t n);
t_list				*ft_lstpushback(t_list **begin,
						void const *content, size_t content_size);
void				ft_lpause(void);
void				ft_tabscpy(char **d, char **s, int i, int j);
char				*ft_strscut(char **src, const char *cut, int o);
void				ft_strswap(char **s1, char **s2);
void				ft_lstdelif_n(t_list **elem, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_atoi_base(char *str, int b);
void				ft_putfloat(double n);
t_matrix			*ft_cre_matrix(int op, int i, int j, ...);
void				ft_print_matrix(t_matrix *a);
t_matrix			*ft_opera_matrix(t_matrix *a, char *s, t_matrix *b);
t_matrix			*ft_add_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_sou_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_vid_matrix(int i, int j);
t_matrix			*ft_mult_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_transpo_matrix(t_matrix *c);
void				ft_del_matrix(t_matrix **a);
t_matrix			*ft_resize_matrix(t_matrix *a, size_t i, size_t j);
double				ft_det_matrix(t_matrix *a);
t_matrix			*ft_dup_matrix(t_matrix *a);
double				ft_pow_f(double nb, unsigned int p);
t_matrix			*ft_com_matrix(t_matrix *a);
t_matrix			*ft_nb_mult_matrix(t_matrix *a, double nb);
t_matrix			*ft_invers_matrix(t_matrix *a);
t_matrix			*ft_div_matrix(t_matrix *a, t_matrix *b);
void				ft_lstprint(t_list *beg, int op);
void				*ft_error_n(int op, char *str, int ker);
int					ft_error_0(int op, char *str, int ker);
void				ft_success(char *s);
char				*ft_itoa_f(double n, unsigned char pre);

#endif
