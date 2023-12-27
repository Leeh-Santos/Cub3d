/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:22:47 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/27 17:50:37 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#define BUFFER_SIZE 1

/*char		*get_next_line(int fd);
size_t		ft_strlen(const char *word);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
char		*cpyfrm2(char *str, int i, int end);
int	ft_strlennl(char *str);
int	is_newline(char *str);
char	*ft_get_line(char *buff, char *line);*/



size_t			ft_strlen(char *str);

char			*ft_strchr(char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

char			*line_only(char *memorycard);
char			*rest4next(char *memorycard);
char			*readuntillinebr(int fd, char *memorycard);


#endif