/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/10/23 20:36:29 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_4_parse(int argc, char *cufile)
{
	int	i;

	int	fd;

	i = 0;
	while (cufile[i])
		i++;
	if (cufile[i] != 'b' || cufile[i - 2] != 'u' || cufile[i - 3] != 'c' || cufile[i - 4] != '.')
		boom("wrong cu format");
	fd = open(cufile, O_RDONLY, 0644);
	if (fd == -1)
	{
		close(fd);
		boom("no able to open your cu      b3d");
	}

}

void	boom(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		boom("deu ruim nos args");
	check_4_parse(argc, argv[1]);
	
		

	return 0;
}