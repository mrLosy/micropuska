/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:55:13 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 20:30:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 48
# endif

int					get_next_line(int fd, char **line);
int					ft_rn(char *str);
size_t				ft_strlen_custom(const char *s);
char				*ft_strjoin_custom(const char *s1, const char *s2);

#endif
