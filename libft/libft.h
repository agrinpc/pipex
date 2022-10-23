/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:01:37 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/23 20:14:48 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define NUM_BUF 14
# define OPEN_MAX 10240

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t n);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *b, int c, size_t n);
int					ft_memcmp(const void *b1, const void *b2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_1(char *s1, char *s2);
char				*ft_strjoin_2(char *s1, char *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,	void *(*f)(void *),
						void (*del)(void *));
char				*ft_strtok(char *str, char sepa);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
int					ft_printf(const char *s, ...);
int					ft_print_condition(char *format, va_list vars);
int					get_uint_size(unsigned int n);
char				*ft_utoa(unsigned int n);
int					is_what(char c);
int					is_left_aligned(char *format);
int					is_blank(char *format, long int n);
int					is_plus(char *format);
int					is_zeroed(char *format);
int					is_capital(char c);
int					is_hash(char *format);
char				*get_format(const char *s, int i);
int					get_min(char *format);
int					get_max(char *format);
char				get_type(char	*format);
char				*get_sign_char(int n, char	*format);
char				*get_hex_char(char *format, char *numbers);
int					get_hex_size(unsigned long int a);
char				*get_hex(unsigned long int a, int size,
						int is_big, int max);
long int			get_abs(long num);
int					print_string(char	*format, char *str);
int					print_int(char *format, long int num);
int					print_uint(char *format, unsigned int num);
int					print_hex(char *format, unsigned long int num, int is_big);
int					print_char(char *format, char c);
char				*return_number(long num, int max);
char				*return_unumber(unsigned int num, int max);
char				*get_next_line(int fd);
char				*ft_gnl_strjoin(char *s1, char *s2,
						int size_s1, int size_s2);
void				ft_strtcpy(char *dest, char *src, int ints[3], int mod);
void				write_num(char *tmp, int num);
int					read_num(char *tmp);
int					ret_nl_make_zero(char *cur, int ret, int mod);

#endif