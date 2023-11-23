/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varparse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:06:18 by learodri@st       #+#    #+#             */
/*   Updated: 2023/11/23 21:08:34 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	vars_all_good(void)
{
	int fd;
	int i;
	
	i = 0;

	while (i <= 3)
	{
		if (!cu()->vars[i])
			boom("empty textures or missconfig in file\n");
		fd = open(cu()->vars[i], O_RDONLY, 0644);
		if (fd == -1)
		{
			close(fd);
			boom("not able to open textures\n");
		}
		close(fd);
		i++;
	}

	if (cu()->c == -1 || cu()->f == -1)
		boom("missing c or f or misconfig in file\n");
	
}