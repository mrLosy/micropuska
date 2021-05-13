/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:47:19 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/17 20:05:05 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				*ft_memset(void *dest, int val, size_t num);
void				ft_bzero(void *s, size_t num);
void				*ft_memcpy(void *destination, const void *source, size_t n);
void				*ft_memccpy(void *dst, const void *src, int ch, size_t n);
void				*ft_memmove(void *dst, const void *source, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
int					ft_strlen(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t a);
int					ft_isalpha(int c);
int					ft_isdigit(int ch);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int a);
int					ft_tolower(int a);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *hst, const char *ndl, size_t size);
void				*ft_calloc(size_t num, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long int n, int fd);
void				ft_putnbr_u_fd(unsigned int n, int fd);
long long			ft_atoi_long(const char *str);
char				*ft_strcpy(char *dst, char const *src);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
#endif
