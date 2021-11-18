/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:46:15 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/23 19:51:03 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_free_array(char **array, int ret_val);

int		gnl_2(char *line, char **tmp, int k, char c);
int		get_next_line(char **line);
int		ft_abs(int nb);
int		ft_strcmp(const char *str_1, const char *str_2);

int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
void	ft_bzero(void *buf, size_t count);
void	*ft_memchr(const void *arr, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *buf, int ch, size_t count);

int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

int		ft_isalpha(char ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_toupper(int ch);
int		ft_isspaace(int c);
int		ft_tolower(int ch);
int		ft_skipspace(const char *s);
int		check_back_n(char *str);

void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strstr(const char *strB, const char *strA);
char	*ft_itoa(int n);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**ft_strsplit(char const *str, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif