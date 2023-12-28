/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:17:07 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/28 20:30:34 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_substr(char const *str, int start, int end)
{
	char	*sub;
	int		i;

	i = 0;
	if (start > end)
		return (NULL);
	sub = malloc(end - start + 2);
	while (start <= end)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

static int	num_splits(char const *str, char c)
{
	int	i;
	int	splits;

	splits = 1;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			splits++;
		i++;
	}
	return (splits);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		start;
	int		i2;

	i = 0;
	i2 = 0;
	split = malloc(sizeof(char *) * num_splits(str, c));
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] && str[i] != c && (!str[i + 1] || (str[i + 1]
					&& str[i + 1] == c)))
		{
			start = i;
			while (!(str[start] && str[start] != c && (start == 0
						|| str[start - 1] == c)))
				start--;
			split[i2++] = ft_substr(str, start, i);
		}
		i++;
	}
	split[i2] = NULL;
	return (split);
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	neg;

	num = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && neg != 0)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		return (num * neg); // return num aqui tava -1 
	return (num * neg);
}