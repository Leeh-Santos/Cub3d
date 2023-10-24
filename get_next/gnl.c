/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:22:23 by learodri@st       #+#    #+#             */
/*   Updated: 2023/10/24 12:25:15 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next.h"

struct s_gnl
{
	char	*buf;
	char	*changer;
	size_t	i;
};

char	*till_nl(int fd, char *buf)
{
	char	*join1;
	char	*join2;
	char	*added;
	int		i;

	i = 0;
	join1 = cpyfrm2(buf, 0, -1);
	join2 = (char *)malloc(BUFFER_SIZE + 1);
	ft_memset(join2, 0, BUFFER_SIZE + 1);
	i = read(fd, join2, BUFFER_SIZE);
	if (i == 0)
	{
		free(join1);
		free(join2);
		return (NULL);
	}
	added = ft_strjoin(join1, join2);
	free(join1);
	free(join2);
	return (added);
}

struct s_gnl	bruh(int fd, char *buf)
{
	struct s_gnl	one;

	one.buf = cpyfrm2(buf, 0, -1);
	one.i = 0;
	while (!one.buf || one.buf[one.i] != '\n')
	{
		while (one.i < ft_strlen(one.buf) && one.buf[one.i] != '\n')
			one.i++;
		if (one.buf != NULL && one.buf[one.i] == '\n')
			break ;
		one.changer = cpyfrm2(one.buf, 0, -1);
		free(one.buf);
		one.buf = till_nl(fd, one.changer);
		if (one.buf == NULL)
			break ;
		free(one.changer);
	}
	return (one);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	struct s_gnl	two;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	two = bruh(fd, buf);
	free(buf);
	buf = cpyfrm2(two.buf, 0, -1);
	free(two.buf);
	if (buf == NULL && two.i == ft_strlen(two.changer))
		return (two.changer);
	two.changer = cpyfrm2(buf, two.i + 1, -1);
	two.buf = cpyfrm2(buf, 0, two.i);
	free(buf);
	if (two.changer != NULL)
		buf = cpyfrm2(two.changer, 0, -1);
	free(two.changer);
	return (two.buf);
}